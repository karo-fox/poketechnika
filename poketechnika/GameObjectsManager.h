#pragma once
#include <vector>
#include "GameObject.h"

class GameObjectsManager
{
private:
	std::vector<GameObject*> gameObjects{};
public:
	int gameObjectsNumber();
	void addGameObjects(std::vector<GameObject*> gos);
	void resetGameObjects();
	void eraseGameObject(GameObject* go);
	void update();
};

