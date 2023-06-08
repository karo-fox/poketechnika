#include <memory>
#include <utility>
#include "Game.h"
#include "MenuScene.h"
#include "GameScene.h"

//Game::Game(int w, int h, bool fullscreen) : 
//    gm(), window(sf::VideoMode(w, h), "Poketechnika"), 
//    rend(window), sm(&rend), im() 
//{
//    if (fullscreen)
//    {
//        window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Poketechnika", sf::Style::Fullscreen);
//        Camera::setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
//    }
//    else Camera::setCameraSize(w, h);
//    rend.setScale();
//}

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
    // TODO: Create all scenes

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

//void Game::processInput() {
//    im.reset_actions();
//    const auto state = sm.getSceneType();
//    im.processInput(window, state);
//
//    static std::map<Action, State> changeStateActions{
//        {Action::ChangeSceneToGame, State::GAME},
//        {Action::ChangeSceneToMenu, State::MAINMENU},
//    };
//    for (const auto& elem : changeStateActions) {
//        if (im.getAction(elem.first)) {
//            gm.unloadMap();
//            sm.changeScene(elem.second);
//            if (elem.second == State::GAME) {
//                gm.loadMap();
//            }
//        }
//    }
//    if (im.getAction(Action::Close)) {
//        gm.unloadMap();
//        window.close();
//    }
//}

//void Game::update() {
//    float time = clock.restart().asMilliseconds();
//    for (auto gameObject : gameObjects) {
//        if (gameObject->isActive()) {
//            gameObject->update(time);
//        }
//    }
//}

//void Game::initGameLoop() {
//    //Create all necessary instances before game starts
//    GameObject::setGameObjectsPtr(&gameObjects);
//    GameObject::setInputManagerPtr(&im);
//    GameScene::setGMPtr(&gm);
//    gm.start();
//    sm.createFirstScene();
//    //Start the loop
//    window.setFramerateLimit(60);
//
//    while (window.isOpen())
//    {
//        //Process Input
//        processInput();
//        //Update
//        update();
//        //Render
//        sm.renderScene();
//    }
//    //Destroy all the things after the window closes
//}

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
        // TODO: Save data
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
}
