#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameObject.h"

Game::Game(int w, int h, bool fullscreen) : gm(load()), window(sf::VideoMode(w, h), "Poketechnika"), rend(window), sm(&rend) {
    if (fullscreen)
        window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Poketechnika", sf::Style::Fullscreen);
    rend.setScale();
}

void Game::processInput() {
    //Handle the player input
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            //placeholder for tests
            if (sm.getCurrentScene() == state::MAINMENU)
            {
                if (event.key.code == sf::Keyboard::A)
                    sm.changeScene(state::GAME);
            }
            if (sm.getCurrentScene() == state::GAME)
            {
                if (event.key.code == sf::Keyboard::D)
                    sm.changeScene(state::MAINMENU);
            }
        }
    }
}

void Game::update() {
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void Game::initGameLoop() {
    //Create all necessary instances before game starts
    
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