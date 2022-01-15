#ifndef BDALY_COMMAND_H
#define BDALY_COMMAND_H

#include <vector>
#include <string>
#include "GameObject.h"

class IBattleCommand
{
protected:
	int weight;

public:
	virtual void execute(GameObject* p_oCaller, GameObject* p_oTarget) = 0;
	virtual ~IBattleCommand() {}
	


	
};

class AttackCommand : public IBattleCommand
{

public:
	virtual void execute(GameObject* p_oCaller, GameObject* p_oTarget)
	{

	}

	AttackCommand(int p_iWeight = 0)
	{
		weight = p_iWeight;
	}

};


#endif