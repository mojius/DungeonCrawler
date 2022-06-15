#pragma once

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

	Orientation GetOrientation();
	void SetOrientation(Orientation m_oOrientation);
	Vec2D GetPos();
	void SetPos(Vec2D m_vPos);
	Player(GameMap& m_mGameMap, Vec2D pos, Player::Orientation orient);
	void PrintGameMap();
	void Move(Orientation m_oDirection);
	void CombatThink();
	std::vector<IBattleCommand*> * GetCommands();


private:
	const bool monster = false;
	Orientation facing;
	GameMap currentLocale;
	Vec2D position;


};