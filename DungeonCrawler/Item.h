#pragma once
#include "GameObject.h"
#include <string>
#include <fstream>
#include <dict/dict.h>
#include <JSON/JSON.h>

class Item : public GameObject
{
private:
	dict* jsonDict;

public:
	Item(std::string dir)
	{
		std::ifstream file(dir);
		char * buffer;
		int fileLength = 0;
		file.seekg(0, file.end);
		fileLength = file.tellg();
		file.seekg(0, file.beg);
		buffer = new char[fileLength + 1];
		file.read(buffer, fileLength);

	
		parse_json(buffer, strlen(buffer), &jsonDict);
		JSONToken_t * token = (JSONToken_t *)dict_get(jsonDict, (char *)"Name");
		printf("");
	}
};