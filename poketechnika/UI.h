#pragma once
#include <vector>
#include <memory.h>
#include "Button.h"

class UI {
	std::vector<Button> _buttons;
	int _active_idx;

	void next();
	void previous();
public:
	UI(const std::vector<Button>& buttons);
};
