#pragma once
#include <pugixml.hpp>

// loads xml file
pugi::xml_document load_xml_file(const char* filename);
