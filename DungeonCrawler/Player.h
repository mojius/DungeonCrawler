#ifndef BDALY_PLAYER_H
#define BDALY_PLAYER_H

#include "GameObject.h"
#include "util.h"
#include "BattleCommand.h"
#include "GameMap.h"

class Player : public GameObject
{

public:
	enum Orientation
	{
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

	Orientation getOrientation();
	void setOrientation(Orientation m_oOrientation);
	Vec2D getPos();
	void setPos(Vec2D m_vPos);
	Player(GameMap& m_mGameMap, Vec2D pos, Player::Orientation orient);
	void printGameMap();
	void move(Orientation m_oDirection);
	std::vector<IBattleCommand*> * getCommands();

	


private:
	Orientation facing;
	GameMap currentLocale;
	Vec2D position;
	std::vector<IBattleCommand*> commands;
};

#endif