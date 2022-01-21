#ifndef BDALY_BATTLESTATS_H
#define BDALY_BATTLESTATS_H

#include "GameObject.h"
#include <string>

struct BattleStats
{
	std::string name;
	const int MAX_HP;
	const int MAX_MP;
	int hp;
	int mp;
	int atk;
	int def;


};

#endif