#include "GameManager.h"
#include "database.h"
#include <iostream>

GameManager::GameManager() : player( Position{ 0, 0 }) {
}

GameManager::~GameManager() {
	save(*this);
}

std::ifstream& operator>> (std::ifstream& in, GameManager& state) {
	in >> state.player.x;
	in >> state.player.y;
	return in;
};


std::ofstream& operator<< (std::ofstream& out, GameManager& state) {
	out << state.player.x << ' ';
	out << state.player.y << ' ';
	return out;
}