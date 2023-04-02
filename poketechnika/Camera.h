#pragma once
#include "GameObject.h"
class Camera : public GameObject
{
public:
	void update();
	Camera(int x, int y);
	~Camera();
};