#pragma once
#include "GameManager.h"
#include <pugixml.hpp>
#include <string>

pugi::xml_document load_xml_file(const std::string& filename);

GameManager load();
void save(GameManager& state);
