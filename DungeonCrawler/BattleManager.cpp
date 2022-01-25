#include "BattleManager.h"
#include <cassert>
#include <tuple>

BattleManager::BattleManager(CombatObject& p_Belligerent1, CombatObject& p_Belligerent2)
{
	assert(!instantiated);
	instantiated = true;

	this->belligerent1 = &p_Belligerent1;
	this->belligerent2 = &p_Belligerent2;

	belligerent2->opponentStats = &p_Belligerent1.stats;
	belligerent1->opponentStats = &p_Belligerent2.stats;

	bool turn = false;
	while (!BattleShouldEnd)
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

	delete p_Belligerent2.opponentStats;
	p_Belligerent2.opponentStats = nullptr;
	delete p_Belligerent1.opponentStats;
	p_Belligerent1.opponentStats = nullptr;
}

BattleManager::~BattleManager()
{
	delete belligerent1;
	belligerent1 = nullptr;
	delete belligerent2;
	belligerent2 = nullptr;
	instantiated = false;
}

//Returns true if the battle should technically end -- any one of the requirements have to be met.
//Returns false if the battle should not end.
bool BattleManager::BattleShouldEnd()
{
	return
		(
			std::get<1>(belligerent1->stats.hp) <= 0 ||
			std::get<1>(belligerent2->stats.hp) <= 0 ||
			belligerent1->stats.fleeSuccess == true ||
			belligerent2->stats.fleeSuccess == true
		);
}