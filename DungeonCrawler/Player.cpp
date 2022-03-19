#include "GameMap.h"
#include "util.h"
#include "Player.h"
#include <iostream>
#include "BattleCommand.h"

Player::Orientation Player::GetOrientation()
{
	return this->facing;
}

void Player::SetOrientation(Player::Orientation m_oOrientation)
{
	this->facing = m_oOrientation;
}

Vec2D Player::GetPos()
{
	return this->position;
}

void Player::SetPos(Vec2D m_vPos)
{
	this->position = m_vPos;
}

Player::Player(GameMap& m_mGameMap, Vec2D pos, Player::Orientation orient): currentLocale(m_mGameMap), position(pos), facing(orient)
{
	type = PLAYER;
	commands.push_back(new AttackCommand());
	hp = { 5,5 };
	str = { 1,1 };
	def = { 0,0 };
	mp = { 0,0 };
	spd = { 25, 25 };
	acc = { 70, 70 };
	eva = { 15, 15 };
	name = "Player";
}

void Player::PrintGameMap()
{
	//Rows...
	for (int i = 0; i < currentLocale.GetSize().y; i++)
	{
		//Columns.
		for (int j = 0; j < currentLocale.GetSize().x; j++)
		{
			GameMap::TileState t = this->currentLocale.GetMapArray()[i][j]->GetTileState();

			//TODO: Tidy this up when operator overloading works.
			if (GetPos().x == j && GetPos().y == i)
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

void Player::Move(Player::Orientation m_oDirection)
{
	Vec2D tempVec = this->GetPos();
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
		this->SetPos(tempVec);

}

void Player::CombatThink()
{
	std::cout << "Which command will you choose?\n";
	for (unsigned int i = 0; i < commands.size(); i++)
	{
		std::cout << i + 1 << " -- " << commands.at(i)->name;
	}
	int decision = 0;
	std::cin >> decision;
	decision -= 1;
	commands.at(decision)->ExecutePlayer(this, opponent);
}
