#include "GeneralInputHandler.h"

GeneralInputHandler::GeneralInputHandler() : InputHandler{} {
	event_actions = {
		{sf::Keyboard::Escape, Action::Close},
	};
}
