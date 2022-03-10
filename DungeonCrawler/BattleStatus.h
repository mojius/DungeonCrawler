#pragma once
#include <string>

class BattleStatus
{
	//Buffs/debuffs:
	//Health, MP, attack, defense, speed, evasion.
	//Other effects:
	//Sleep, Poison
protected:

public:
	int buffTimer;
	virtual void Execute() = 0;
	std::string name;
};

class DefendStatus : public BattleStatus
{
	void Execute()
	{

	}
};