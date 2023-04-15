#include "GameObjectsManager.h"

int GameObjectsManager::gameObjectsNumber() {
    return gameObjects.size();
}

void GameObjectsManager::addGameObjects(std::vector<GameObject*> gos) {
    for (auto go : gos) {
        gameObjects.push_back(go);
    }
}

void GameObjectsManager::resetGameObjects() {
    gameObjects.clear();
}

void GameObjectsManager::eraseGameObject(GameObject* go) {
    for (int i{}; i < gameObjects.size(); i++) {
        if (gameObjects.at(i) == go) {
            gameObjects.erase(gameObjects.begin() + i);
        }
    }
}

void GameObjectsManager::update() {
    for (auto go : gameObjects) {
        go->update();
    }
}