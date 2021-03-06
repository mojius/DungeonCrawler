#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <cmath>

#include "util.h"
#include "CombatObject.h"

class IBattleCommand
{
protected:
	int weight = 0;

public:
	virtual void execute(CombatObject& p_oCaller, CombatObject& p_oTarget) = 0;
	virtual ~IBattleCommand() {}
	std::string name;
};

class AttackCommand : public IBattleCommand
{

public:
	void execute(CombatObject& p_oCaller, CombatObject& p_oTarget)
	{

		if (!rollPhysicalHit) return;
		
		std::cout << p_oCaller.name << " attacks!\n";
		int damage = rollPhysicalAttack(p_oCaller, p_oTarget);
		if (damage > 0)
		{
			std::cout << p_oCaller.name << " hits for " << damage << " damage!\n";
			p_oTarget.SetCurHP(std::max((p_oTarget.GetCurHP() - damage), 0));
		}
		else if (damage <= 0) std::cout << p_oCaller.name << "'s attack grazes off!\n";

	};

	AttackCommand(int p_iWeight = 0)
	{
		weight = p_iWeight;
		name = "Attack";
	};

};

class FleeCommand : public IBattleCommand
{
	void execute(CombatObject& p_oCaller, CombatObject& p_oTarget)
	{
		if (((rand() % 3) + 1) == 3)
		{
			p_oCaller.fleeSuccess = true;
			std::cout << p_oCaller.name << " successfully fled!!\n";
			return;
		}
		std::cout << p_oCaller.name << " could not run away!!\n";
	}
};

class DefendCommand : public IBattleCommand
{
	//Somehow add a temporary bonus to defense.
};


