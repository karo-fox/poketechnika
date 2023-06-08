#include <iostream>
#include <memory>

#include "GameScene.h"
#include "Map.h"
#include "Exception.h"
#include "database.h"
#include "Player.h"

enum class MapId {
	FACULTY_ENTRANCE, FACULTY_INTERIOR, PARK
};

std::map<MapId, const char*> map_files{
	{MapId::FACULTY_ENTRANCE, "data/faculty_entrance.xml"},
};

GameScene::GameScene() 
	: Scene{}, 
	ih{ {}, {
		{ sf::Keyboard::W, Action::MoveUp },
		{ sf::Keyboard::S, Action::MoveDown },
		{ sf::Keyboard::D, Action::MoveRight },
		{ sf::Keyboard::A, Action::MoveLeft },
	} }, game_objects{}, map{}, 
	background{ "assets/textures/background_game.png", sf::Vector2f{0, 0} } 
{
	load_map();
	Player player{map};
	player.setActive(true);
	game_objects.push_back(std::make_shared<Player>(player));
	Camera camera{0, 0};
	game_objects.push_back(std::make_shared<Camera>(camera));

	std::cout << "Created Game Scene" << '\n';
}

void GameScene::load_map() {
	try {
		pugi::xml_document map_file = load_xml_file(map_files.at(MapId::FACULTY_ENTRANCE));
		pugi::xml_node map_node = map_file.child("map");
		map = map_from_xml(map_node);
	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
}

void GameScene::update(float time_elapsed) {
	for (auto& go : game_objects) {
		if (go->isActive()) {
			go->update(time_elapsed, ih, map);
		}
	}
}

void GameScene::render(Renderer& renderer) {
	renderer.draw(background);
	renderer.draw(map, dynamic_cast<Camera&>(*game_objects.at(1))); // TODO: Some better container for this
	renderer.draw(dynamic_cast<Drawable&>(*game_objects.at(0)));
}

void GameScene::process_input(sf::RenderWindow& window) {
	ih.reset_actions();
	ih.process_input(window);
}
