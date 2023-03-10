#include "State.h"
#include "database.h"
#include <iostream>

State::State() : player( Position{ 0, 0 }) {
}

State::~State() {
	save(*this);
}

std::ifstream& operator>> (std::ifstream& in, State& state) {
	in >> state.player.x;
	in >> state.player.y;
	return in;
};


std::ofstream& operator<< (std::ofstream& out, State& state) {
	out << state.player.x << ' ';
	out << state.player.y << ' ';
	return out;
}