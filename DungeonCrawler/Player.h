#pragma once

#include "GameObject.h"
#include "util.h"
#include "BattleCommand.h"
#include "GameMap.h"
#include "CombatObject.h"

class Player : public CombatObject
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
	void CombatThink();
	std::vector<IBattleCommand*> * getCommands();

private:
	Orientation facing;
	GameMap currentLocale;
	Vec2D position;

};