#pragma once
#include <vector>
#include <memory.h>
#include "Button.h"
#include "GameObject.h"

class UI : GameObject {
	int _active_idx;

	void next();
	void previous();
	
	void unselect();
	void unselect(int id);
public:
	void select();
	std::vector<Button> _buttons;

	UI(const std::vector<Button>& buttons = {});
	Action click() const;
	void update(float elapsedTime, InputHandler& ih);
	void update(float elapsedTime, InputHandler& ih, int first, int size);
	void resetSelectButton();
};
