#pragma once

#include "GameObject.h"
#include "util.h"
#include "BattleStats.h"
#include "Player.h"
#include <vector>

class Enemy : public CombatObject
{
private:
	friend class Player;
};