#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Camera.h"
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
                gm.map = gm.loadMap(MapId::TEST);
            }
        }
    }
    if (im.getAction(Action::Close)) {
        gm.unloadMap();
        window.close();
    }

    im.reset_actions();
}

void Game::update() {
    for (auto gameObject : gameObjects) {
        if (gameObject->isActive()) {
            gameObject->update();
        }
    }
}

void Game::initGameLoop() {
    //Create all necessary instances before game starts
    GameObject::setGameObjectsPtr(&gameObjects);
    GameScene::setGMPtr(&gm);
    sm.createFirstScene();
    //Start the loop
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