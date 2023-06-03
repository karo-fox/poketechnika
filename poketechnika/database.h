#pragma once
#include "GameManager.h"
#include <pugixml.hpp>
#include <string>

pugi::xml_document load_xml_file(const char* filename);

GameManager load();
void save(GameManager& state);
