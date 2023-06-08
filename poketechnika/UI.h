#pragma once
#include <vector>
#include <memory.h>
#include "Button.h"
#include "GameObject.h"

class UI : GameObject {
	std::vector<Button> _buttons;
	int _active_idx;

	void next();
	void previous();
public:
	UI(const std::vector<Button>& buttons = {});
	Action click() const;
	void update(float elapsedTime, const InputHandler& ih);
};
