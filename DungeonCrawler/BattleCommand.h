#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <tuple>

#include "util.h"
#include "BattleStats.h"

class IBattleCommand
{
protected:
	int weight;

public:
	virtual void execute(BattleStats& p_oCaller, BattleStats& p_oTarget) = 0;
	virtual ~IBattleCommand() {}
	std::string name;
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
			std::get<1>(p_oTarget.hp) -= damage;
		}
		else if (damage <= 0) std::cout << p_oCaller.name << " missed!\n";

	};

	AttackCommand(int p_iWeight = 0)
	{
		weight = p_iWeight;
		name = "Attack";
	};

};

class FleeCommand : public IBattleCommand
{
	void execute(BattleStats& p_oCaller, BattleStats& p_oTarget)
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


