#pragma once
#include <vector>
#include <memory.h>
#include "Button.h"
#include "GameObject.h"

class UI : GameObject {
	int _active_idx;

	void next();
	void previous();
	void select();
	void unselect();
public:
	std::vector<Button> _buttons;

	UI(const std::vector<Button>& buttons = {});
	Action click() const;
	void update(float elapsedTime, const InputHandler& ih);
};
