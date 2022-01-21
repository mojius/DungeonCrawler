#ifndef BDALY_ENEMY_H
#define BDALY_ENEMY_H

#include "GameObject.h"
#include "util.h"
#include "BattleStats.h"
#include "Player.h"
#include <vector>

class Enemy : public GameObject
{
private:
	BattleStats stats;
	friend class Player;
	std::vector<IBattleCommand*> commands;
};


#endif