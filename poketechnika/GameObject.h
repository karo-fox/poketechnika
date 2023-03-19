#pragma once
class GameObject
{
public:
	GameObject();
	virtual void update();
protected:
	float posX;
	float posY;
	bool active;
};