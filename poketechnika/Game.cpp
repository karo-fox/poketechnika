#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Camera.h"
#include <vector>

#include <iostream>
using namespace std;

Game::Game(int w, int h, bool fullscreen) : gm(load()), window(sf::VideoMode(w, h), "Poketechnika"), rend(window), sm(&rend) {
    if (fullscreen)
    {
        window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Poketechnika", sf::Style::Fullscreen);
        Camera::setCameraSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    }
    else Camera::setCameraSize(w, h);
    rend.setScale();
}

void Game::processInput() {
    //Handle the player input
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            gm.unloadMap();
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                gm.unloadMap();
                window.close();
            }
            //placeholder for tests
            if (sm.getCurrentScene() == state::MAINMENU)
            {
                if (event.key.code == sf::Keyboard::A)
                {
                    sm.changeScene(state::GAME);
                    gm.loadMap();
                }
                    
            }
            if (sm.getCurrentScene() == state::GAME)
            {
                if (event.key.code == sf::Keyboard::D)
                {
                    sm.changeScene(state::MAINMENU);
                    gm.unloadMap();
                }
            }
        }
    }
}

//void Game::update() {
//    for (int i = 0; i < gom.gameObjectsNumber(); i++)
//    {
//        gameObjects[i]->update();
//    }
//}

void Game::initGameLoop() {
    //Create all necessary instances before game starts
    //GameObject::setGameObjectsPtr(&gameObjects);
    //GameScene::setGMPtr(&gm);
    sm.createFirstScene();
    //Start the loop
    while (window.isOpen())
    {
        //Process Input
        processInput();
        //Update
        gom.update();
        //Render
        sm.renderScene();
    }
    //Destroy all the things after the window closes
}

