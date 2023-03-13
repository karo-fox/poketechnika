#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

Game::Game() : gm(load()) {}

void Game::processInput(sf::RenderWindow& window) {
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
    //Run through all GameObjects and update them
}

void Game::initGameLoop(int width, int height) {
    //Create all necessary instances before game starts
    
    //Create window
    sf::RenderWindow window(sf::VideoMode(width, height), "Poketechnika");
    //Start the loop
    while (window.isOpen())
    {
        //Process Input
        processInput(window);
        //Update
        update();
        //Render
        sm.renderScene(window);
    }
    //Destroy all the things after the window closes
}