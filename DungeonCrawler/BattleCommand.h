#ifndef BDALY_COMMAND_H
#define BDALY_COMMAND_H

#include <vector>
#include <string>
#include "BattleStats.h"
#include <iostream>

class IBattleCommand
{
protected:
	int weight;

public:
	virtual void execute(BattleStats& p_oCaller, BattleStats& p_oTarget) = 0;
	virtual ~IBattleCommand() {}
};

class AttackCommand : public IBattleCommand
{

public:
	void execute(BattleStats& p_oCaller, BattleStats& p_oTarget)
	{
		std::cout << p_oCaller.name << " attacks!\n";
		int damage = rollPhysicalAttack(p_oCaller, p_oTarget);
		if (damage > 0)
		{
			std::cout << p_oCaller.name << " hits for " << damage << " damage!\n";
			p_oTarget.hp -= damage;
		}
		else if (damage <= 0) std::cout << p_oCaller.name << " missed!\n";

	};

	AttackCommand(int p_iWeight = 0)
	{
		weight = p_iWeight;
	};

};

class FleeCommand : public IBattleCommand
{
	void execute(BattleStats& p_oCaller, BattleStats& p_oTarget)
	{
		if (((rand() % 3) + 1) == 3)
		{
			//End the battle
		}
	}
	

};

class DefendCommand : public IBattleCommand
{
	//Somehow add a temporary bonus to defense.
};





#endif