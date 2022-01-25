#pragma once
#include "GameObject.h"
#include "BattleStats.h"

class CombatObject: public GameObject
{
protected:
	BattleStats stats;
	BattleStats* opponentStats;
	friend class BattleManager;
	virtual void CombatThink() = 0;
};

