#include "BattleManager.h"
#include <cassert>
#include <iostream>

bool BattleManager::instantiated = false;

BattleManager::BattleManager(CombatObject& p_Belligerent1, CombatObject& p_Belligerent2)
{
	assert(!instantiated);
	instantiated = true;

	std::cout << p_Belligerent1.name << " encounters enemy " << p_Belligerent2.name << "\n";

	this->belligerent1 = &p_Belligerent1;
	this->belligerent2 = &p_Belligerent2;

	belligerent2->opponent = &p_Belligerent1;
	belligerent1->opponent = &p_Belligerent2;

	bool turn = false;
	while (!BattleShouldEnd())
	{ 
		switch (turn)
		{
		case false:
			belligerent1->CombatThink();
			break;
		case true:
			belligerent2->CombatThink();
			break;
		}
		
		if (BattleShouldEnd()) break;

		turn = !turn;
	}

	belligerent2->opponent = nullptr;
	belligerent1->opponent = nullptr;
}

BattleManager::~BattleManager()
{
	belligerent1 = nullptr;
	belligerent2 = nullptr;
	instantiated = false;
}

//Returns true if the battle should technically end -- any one of the requirements have to be met.
//Returns false if the battle should not end.
bool BattleManager::BattleShouldEnd()
{

	bool gotAway = belligerent1->GetCurHP() <= 0 ||
		belligerent2->GetCurHP() <= 0 ||
		belligerent1->fleeSuccess == true ||
		belligerent2->fleeSuccess == true;
	return gotAway;
}