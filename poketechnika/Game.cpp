#include <utility>
#include "Game.h"
#include "MenuScene.h"
#include "GameScene.h"

Game::Game(int width, int height, bool fullscreen) 
    : window{ sf::VideoMode(width, height), "Poketechnika" }, sm{ window }, clock{}, 
    ih{ {
        {sf::Keyboard::Escape, Action::Close}, 
        {sf::Keyboard::L, Action::ChangeSceneToGame},
        {sf::Keyboard::K, Action::ChangeSceneToMenu},
       }, {} }, scenes{}
{
    MenuScene menu_scene{};
    GameScene game_scene{};
    scenes = {
        {State::MAINMENU, std::make_shared<MenuScene>(menu_scene)},
        {State::GAME, std::make_shared<GameScene>(game_scene)},
    };
    // TODO: Create all scenes (battle, error)

    if (fullscreen) {
        width = sf::VideoMode::getDesktopMode().width;
        height = sf::VideoMode::getDesktopMode().height;
        window.create(
            sf::VideoMode(width, height), "Poketechnika", sf::Style::Fullscreen
        );
    }
    Camera::setCameraSize(width, height);
    sm.set_renderer_scale();
}

void Game::process_input() {
    ih.reset_actions();
    ih.process_input(window);
    for (auto& elem : change_scene) {
        if (ih.get_action(elem.first)) {
            auto next_scene{ scenes.at(elem.second) };
            sm.set_scene(std::move(next_scene));
        }
    }
    if (ih.get_action(Action::Close)) {
        window.close();
    }
}

void Game::run() {
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        process_input();
        float time = clock.restart().asMilliseconds();
        sm.run_scene(time);
    }
    // TODO: Save all data after window closes
}
