#include <iostream>
#include "GameScene.h"
#include "Player.h"
#include "Camera.h"
#include "Exception.h"
#include "database.h"

const char* GOS_FILE_PATH{ "data/gos.xml" };

enum class MapId {
	FACULTY_ENTRANCE, FACULTY_INTERIOR, PARK
};

std::map<MapId, const char*> map_files{
	{MapId::FACULTY_ENTRANCE, "data/faculty_entrance.xml"},
};

GameScene::GameScene() 
	: Scene{},
	game_objects{
		{ GO::PLAYER, {} }, { GO::CAMERA, {} }, { GO::POKEMON, {} }
	}, map{}
{
	load_map();
	// Initialize all Game Objects and add them to container
	Player player{map};
	auto player_ptr{ std::make_shared<Player>(player)};
	game_objects.at(GO::PLAYER).push_back(player_ptr);
	auto player_ptr2{ player_ptr };
	Camera camera{22, 44, player_ptr2};
	camera.setBoundaries(map.getMapSize());
	game_objects.at(GO::CAMERA).push_back(std::make_shared<Camera>(camera));

	load_gos();

	std::cout << "Created Game Scene" << '\n';
}

void GameScene::update(float time_elapsed, InputHandler& ih) {
	for (auto& go_vec : game_objects) {
		for (auto& go : go_vec.second) {
			if (go->isActive()) {
				go->update(time_elapsed, ih);
			}
		}
	}
	ui.update(time_elapsed, ih);
}

void GameScene::render(Renderer& renderer) {
	// Draw map
	renderer.draw(map, dynamic_cast<Camera&>(*game_objects.at(GO::CAMERA).at(0)));
	// Draw player
	renderer.draw(dynamic_cast<Drawable&>(*game_objects.at(GO::PLAYER).at(0)), dynamic_cast<Camera&>(*game_objects.at(GO::CAMERA).at(0)).getPosition());
}

void GameScene::save_gos() {
	try {
		pugi::xml_document gos_file = load_xml_file(GOS_FILE_PATH);
		pugi::xml_node gos_node = gos_file.child("gos");

		pugi::xml_node player_node = gos_node.child("player");
		dynamic_cast<Player&>(*game_objects.at(GO::PLAYER).at(0)).save(player_node);

		pugi::xml_node camera_node = gos_node.child("camera");
		dynamic_cast<Camera&>(*game_objects.at(GO::CAMERA).at(0)).save(camera_node);

		gos_file.save_file(GOS_FILE_PATH);
	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
}

void GameScene::load_gos() {
	try {
		pugi::xml_document gos_file = load_xml_file(GOS_FILE_PATH);
		pugi::xml_node gos_node = gos_file.child("gos");

		pugi::xml_node player_node = gos_node.child("player");
		dynamic_cast<Player&>(*game_objects.at(GO::PLAYER).at(0)).load(player_node);

		pugi::xml_node camera_node = gos_node.child("camera");
		dynamic_cast<Camera&>(*game_objects.at(GO::CAMERA).at(0)).load(player_node);

	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
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