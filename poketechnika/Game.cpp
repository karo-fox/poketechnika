#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Camera.h"
#include "Player.h"
#include <vector>
#include <map>

#include <iostream>
using namespace std;

Game::Game(int w, int h, bool fullscreen) : 
    gm(), window(sf::VideoMode(w, h), "Poketechnika"), 
    rend(window), sm(&rend), im() 
{
    if (fullscreen)
    {
        window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Poketechnika", sf::Style::Fullscreen);
        Camera::setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    }
    else Camera::setCameraSize(w, h);
    rend.setScale();
}

void Game::processInput() {
    im.reset_actions();
    const auto state = sm.getSceneType();
    im.processInput(window, state);

    static std::map<Action, State> changeStateActions{
        {Action::ChangeSceneToGame, State::GAME},
        {Action::ChangeSceneToMenu, State::MAINMENU},
    };
    for (const auto& elem : changeStateActions) {
        if (im.getAction(elem.first)) {
            gm.unloadMap();
            sm.changeScene(elem.second);
            if (elem.second == State::GAME) {
                gm.loadMap();
            }
        }
    }
    if (im.getAction(Action::Close)) {
        gm.unloadMap();
        window.close();
    }
}

void Game::update() {
    float time = clock.restart().asMilliseconds();
    for (auto gameObject : gameObjects) {
        if (gameObject->isActive()) {
            gameObject->update(time);
        }
    }
}

void Game::initGameLoop() {
    //Create all necessary instances before game starts
    GameObject::setGameObjectsPtr(&gameObjects);
    GameObject::setInputManagerPtr(&im);
    GameScene::setGMPtr(&gm);
    gm.start();
    sm.createFirstScene();
    //Start the loop
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        //Process Input
        processInput();
        //Update
        update();
        //Render
        sm.renderScene();
    }
    //Destroy all the things after the window closes
}