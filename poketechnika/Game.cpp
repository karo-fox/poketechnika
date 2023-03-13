#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

Game::Game() : gm(load()) {}

void Game::ProcessInput(sf::RenderWindow& window) {
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
                    sm.ChangeScene(state::GAME);
            }
            if (sm.getCurrentScene() == state::GAME)
            {
                if (event.key.code == sf::Keyboard::D)
                    sm.ChangeScene(state::MAINMENU);
            }
        }
    }
}

void Game::GameUpdate() {
    //Run through all GameObjects and update them
}

void Game::InitGameLoop(int width, int height) {
    //Create all necessary instances before game starts
    
    //Create window
    sf::RenderWindow window(sf::VideoMode(width, height), "Poketechnika");
    //Start the loop
    while (window.isOpen())
    {
        //Process Input
        ProcessInput(window);
        //Update
        GameUpdate();
        //Render
        sm.RenderScene(window);
    }
    //Destroy all the things after the window closes
}