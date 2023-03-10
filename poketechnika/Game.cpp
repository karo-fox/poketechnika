#include "Game.h"
#include "database.h"
#include <SFML/Graphics.hpp>

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
        }
    }
}

void Game::GameUpdate() {
    //Run through all GameObjects and update them
}

void Game::Render(sf::RenderWindow& window) {
    //Clear the window
    window.clear();
    //Draw all the things

    //Display the window
    window.display();
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
        Render(window);
    }
    //Destroy all the things after the window closes
}