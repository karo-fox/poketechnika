#pragma once
#include <vector>
#include <memory.h>
#include "Button.h"
#include "GameObject.h"

class UI : GameObject {
	int _active_idx;

	// selects next item
	void next();
	// selects previous item
	void previous();
	
	// marks button as unselected
	void unselect();
	void unselect(int id);
public:
	// marks button as selected
	void select();
	std::vector<std::shared_ptr<Button>> _buttons;

	UI(const std::vector<std::shared_ptr<Button>>& buttons = {});
	// returns action of selected button
	Action click() const;
	void update(float elapsedTime, InputHandler& ih);
	void update(float elapsedTime, InputHandler& ih, int first, int size);
	// unselects all buttons
	void resetSelectButton(int idx);
};
