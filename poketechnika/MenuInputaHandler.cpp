#include "MenuInputHandler.h"

MenuInputHandler::MenuInputHandler() : InputHandler{} {
	event_actions = {
		{sf::Keyboard::L, Action::ChangeSceneToGame}
	};
}
