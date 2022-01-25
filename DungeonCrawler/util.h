#pragma once

#include "BattleStats.h"
#include <random>

class Vec2D
{

public:
	int x;
	int y;
	
	Vec2D(int p_X, int p_Y) : x(p_X), y(p_Y) {}

	bool operator==(const Vec2D& rhs) { return x == rhs.x && y == rhs.y; }
};

inline int rollPhysicalAttack(BattleStats& p_oCaller, BattleStats& p_oTarget)
{
	//put evasion/accuracy calculation here
	int damage = (std::get<1>(p_oCaller.atk) - std::get<1>(p_oCaller.def));
	return damage;
}

