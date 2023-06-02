#include "database.h"
#include "GameManager.h"
#include "Exception.h"

#include <iostream>
#include <fstream>
#include <string>

pugi::xml_document load_xml_file(const char* filename) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename);
	if (result) {
		return doc;
	}
	throw Exception(result.description());
}
