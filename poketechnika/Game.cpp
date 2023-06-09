#include <utility>
#include "Game.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "BattleScene.h"
#include "Button.h"

Game::Game(int width, int height, bool fullscreen) 
    : window{ sf::VideoMode(width, height), "Poketechnika" }, sm{ window }, 
    clock{}, state{ State::MAINMENU }, ih{state}, scenes{}
{
    if (fullscreen) {
        width = sf::VideoMode::getDesktopMode().width;
        height = sf::VideoMode::getDesktopMode().height;
        window.create(
            sf::VideoMode(width, height), "Poketechnika", sf::Style::Fullscreen
        );
    }
    Camera::setCameraSize(width, height);
    sm.set_renderer_scale();
    Button::load_font();

    // Create all scenes used in game
    MenuScene menu_scene{};
    GameScene game_scene{};
    BattleScene battle_scene{};
    scenes = {
        {State::MAINMENU, std::make_shared<MenuScene>(menu_scene)},
        {State::GAME, std::make_shared<GameScene>(game_scene)},
        {State::BATTLE, std::make_shared<BattleScene>(battle_scene)},
    };
    // TODO: Create all scenes (battle, error)

    // Set first scene to menu
    auto first_scene{ scenes.at(State::MAINMENU) };
    sm.set_scene(std::move(first_scene));
}

void Game::process_input() {
    ih.reset_actions();
    ih.process_input(window);
    if (ih.get_action(Action::ClickButton)) {
        const auto action = scenes.at(state)->ui.click();
        ih.add_action(action);
    }
    for (auto& elem : change_scene) {
        if (ih.get_action(elem.first)) {
            state = elem.second;
            auto next_scene{ scenes.at(state) };
            sm.set_scene(std::move(next_scene));
        }
    }
    if (ih.get_action(Action::Close)) {
        window.close();
    }
}

void Game::run() {
    window.setFramerateLimit(60);

    // Game loop
    while (window.isOpen()) {
        process_input();
        float time = clock.restart().asMilliseconds();
        sm.run_scene(time, ih);
    }
    // TODO: Save all data after window closes
}
