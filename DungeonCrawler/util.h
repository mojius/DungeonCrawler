#pragma once

#include "CombatObject.h"
#include <random>

class Vec2D
{

public:
	int x;
	int y;
	
	Vec2D(int p_X, int p_Y) : x(p_X), y(p_Y) {}

	bool operator==(const Vec2D& rhs) { return x == rhs.x && y == rhs.y; }
};

inline bool rollPhysicalHit(CombatObject& p_oCaller, CombatObject& p_oTarget)
{
	//accuracy check.
	int n1 = rand() % 100;
	if (n1 >= p_oCaller.GetCurACC())
	{
		std::cout << p_oCaller.name << " misses!\n";
		return false;
	}
	//evasion check.
	int n2 = rand() % 100;
	if (n2 < p_oTarget.GetCurEVA())
	{
		std::cout << p_oCaller.name << " misses!\n";
		return false;
	}

	return true;
}

inline int rollPhysicalDamage(CombatObject& p_oCaller, CombatObject& p_oTarget)
{
	if (p_oCaller.monster)
	{

	}
	else
	{
		switch(p_oCaller.rhand.
	}
	int damage = (p_oCaller.GetCurATK() - p_oTarget.GetCurDEF());
	return damage;
}