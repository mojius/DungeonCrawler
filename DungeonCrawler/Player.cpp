#include "GameMap.h"
#include "util.h"
#include "Player.h"
#include <iostream>
#include "BattleCommand.h"

Player::Orientation Player::getOrientation()
{
	return this->facing;
}

void Player::setOrientation(Player::Orientation m_oOrientation)
{
	this->facing = m_oOrientation;
}

Vec2D Player::getPos()
{
	return this->position;
}

void Player::setPos(Vec2D m_vPos)
{
	this->position = m_vPos;
}

Player::Player(GameMap& m_mGameMap, Vec2D pos, Player::Orientation orient): currentLocale(m_mGameMap), position(pos), facing(orient)
{
	stats.commands.push_back(new AttackCommand());
}

void Player::printGameMap()
{
	//Rows...
	for (int i = 0; i < currentLocale.GetSize().y; i++)
	{
		//Columns.
		for (int j = 0; j < currentLocale.GetSize().x; j++)
		{
			GameMap::TileState t = this->currentLocale.GetMapArray()[i][j]->GetTileState();

			//TODO: Tidy this up when operator overloading works.
			if (getPos().x == j && getPos().y == i)
				std::cout << 'P';
			else
			{
				switch (t)
				{
				case GameMap::TileState::SOLID:
					std::cout << '=';
					break;
				case GameMap::TileState::AIR:
					std::cout << '-';
					break;
				case GameMap::TileState::ENTRANCE:
					std::cout << 'v';
					break;
				case GameMap::TileState::EXIT:
					std::cout << '^';
					break;
				}
			}

			
		}
		std::cout << '\n';
	}
}

void Player::move(Player::Orientation m_oDirection)
{
	Vec2D tempVec = this->getPos();
	Vec2D size = this->currentLocale.GetSize();
	switch (m_oDirection)
	{
	case NORTH:
		tempVec.y--;
		break;
	case SOUTH:
		tempVec.y++;
		break;
	case EAST:
		tempVec.x++;
		break;
	case WEST:
		tempVec.x--;
		break;
	}

	if (tempVec.x > -1
		&& tempVec.y > -1
		&& tempVec.x < size.x
		&& tempVec.y < size.y
		&& this->currentLocale.GetMapArray()[tempVec.y][tempVec.x]->GetTileState() != GameMap::TileState::SOLID)
		this->setPos(tempVec);

}

void Player::CombatThink()
{
	std::cout << "Which command will you choose?\n";
	for (int i = 0; i < stats.commands.size(); i++)
	{
		std::cout << i << " -- " << stats.commands.at(i)->name;
	}
	int decision = 0;
	std::cin >> decision;
	stats.commands.at(decision)->execute(&stats, 
}
