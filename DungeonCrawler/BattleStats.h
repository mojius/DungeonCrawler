#pragma once

#include "GameObject.h"
#include <string>
#include <tuple>
#include <vector>
#include "BattleCommand.h"

class BattleStats
{
public:
	std::string name;
	std::tuple <int, int> hp;
	std::tuple <int, int> mp;
	std::tuple <int, int> atk;
	std::tuple <int, int> def;
	bool fleeSuccess;
	std::vector<IBattleCommand*> commands;
};
