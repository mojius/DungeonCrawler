#pragma once
#include "CombatObject.h"

class BattleManager
{
public:
	BattleManager(CombatObject& m_Belligerent1, CombatObject& m_Belligerent2);
	~BattleManager();

private:
	static bool instantiated;
	CombatObject* belligerent1;
	CombatObject* belligerent2;

	//Checks the conditions of the battle -- whether either character has fled, or their health is less than/equals zero.
	bool BattleShouldEnd();



};

