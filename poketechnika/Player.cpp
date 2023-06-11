#include "Player.h"
#include "actions.h"

Player::Player(const Map& map) 
	: GameObject{}, Drawable{ "assets/textures/player.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f{12 * 64, 8 * 64} }, _map{ std::make_shared<Map>(map) }
{
	size = sf::Vector2f(32, 32);
	speed = 0.10f;
	animation = CurrentAnimation::IDLE;
	face = Faceing::DOWN;
	animDur = 0;
}

void Player::update(float elapsedTime, InputHandler& ih)
{
	// Movement logic
	movementLogic(elapsedTime, ih);
	updateSprite();
}

void Player::movementLogic(float elapsedTime, InputHandler& ih)
{
	// Each if checks for one direction, for both start and end of player graphics (size)
	sf::Vector2f move(0, 0);
	if (ih.get_action(Action::MoveUp) &&
		_map->isPassable(sf::Vector2f(position.x, position.y - speed * elapsedTime)) &&
		_map->isPassable(sf::Vector2f(position.x + size.x, position.y - speed * elapsedTime)))
	{
		move += sf::Vector2f(0, -speed * elapsedTime);
		face = Faceing::DOWN;
	}
	if (ih.get_action(Action::MoveDown) &&
		_map->isPassable(sf::Vector2f(position.x, position.y + size.y + speed * elapsedTime)) &&
		_map->isPassable(sf::Vector2f(position.x + size.x, position.y + size.y + speed * elapsedTime)))
	{
		move += sf::Vector2f(0, speed * elapsedTime);
		face = Faceing::UP;
	}
	if (ih.get_action(Action::MoveLeft) &&
		_map->isPassable(sf::Vector2f(position.x - speed * elapsedTime, position.y)) &&
		_map->isPassable(sf::Vector2f(position.x - speed * elapsedTime, position.y + size.y)))
	{
		move += sf::Vector2f(-speed * elapsedTime, 0);
		face = Faceing::LEFT;
	}
	if (ih.get_action(Action::MoveRight) &&
		_map->isPassable(sf::Vector2f(position.x + size.x + speed * elapsedTime, position.y)) &&
		_map->isPassable(sf::Vector2f(position.x + size.x + speed * elapsedTime, position.y + size.y)))
	{
		move += sf::Vector2f(speed * elapsedTime, 0);
		face = Faceing::RIGHT;
	}
	position += move;
	// Change frame
	if (move != sf::Vector2f(0,0))
	{
		if (animation == CurrentAnimation::RUNNING1) {
			if (animDur > 10) {
				animation = CurrentAnimation::RUNNING2;
				animDur = 0;
			}
			else animDur++;
		}
		else if (animation == CurrentAnimation::RUNNING2) {
			if (animDur > 10) {
				animation = CurrentAnimation::RUNNING3;
				animDur = 0;
			}
			else animDur++;
		}
		else {
			if (animDur > 10) {
				animation = CurrentAnimation::RUNNING1;
				animDur = 0;
			}
			else animDur++;
		}
	}
	else {
		animation = CurrentAnimation::IDLE;
		animDur = 0;
	}
	// Checking for encounter
	if (move != sf::Vector2f(0, 0)
		&& _map->isTileType(position + sf::Vector2f(size.x / 2, size.y / 2), tileTypes::BUSH)
		&& ih.randomizer(1))
	{
		ih.add_action(Action::RandomPokemon);
		ih.add_action(Action::ChangeSceneToBattle);
	}
	if (move != sf::Vector2f(0, 0) 
		&& _map->isTileType(position + sf::Vector2f(size.x / 2, size.y / 2), tileTypes::BOSS)) 
	{
		ih.add_action(Action::ChangeSceneToBoss);
	}
}

sf::Vector2f Player::getPosition()
{
	return position;
}

void Player::save(pugi::xml_node& node) {
	pugi::xml_node active_node = node.child("active");
	active_node.first_child().text().set(active);
}

void Player::load(pugi::xml_node& node) {
	pugi::xml_node active_node = node.child("active");
	active = active_node.first_child().text().as_bool();
}

void Player::updateSprite() {
	sf::IntRect rect(0, 0, 16, 16);
	sprite.setRotation(0);
	if (animation == CurrentAnimation::RUNNING1) rect.left += 16;
	else if (animation == CurrentAnimation::RUNNING3) rect.left += 32;
	if (face == Faceing::RIGHT) rect.left += 48;
	else if (face == Faceing::LEFT) rect.left += 96;
	else if (face == Faceing::DOWN) rect.left += 144;
	texture.loadFromFile(file, rect);
	sprite.setTexture(texture);
	sprite.setScale(2, 2);
}