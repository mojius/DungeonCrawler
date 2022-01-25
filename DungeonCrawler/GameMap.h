#pragma once

#include "util.h"
#include <string>
#include <vector>
#include "GameObject.h"

class GameMap
{

public:

	enum TileState { AIR, SOLID, ENTRANCE, EXIT };
	class GameMapTile
	{
	
	public:
		GameMapTile(GameMap::TileState p_state = GameMap::TileState::AIR);
		GameMap::TileState GetTileState();
		std::vector<GameObject*>* GetObjectList();

	private:

		GameMap::TileState state;
		std::vector<GameObject*> objects;
	};

	GameMapTile*** GetMapArray();
	GameMap(std::string directory, bool bordersAreExitsNotWalls = false);
	Vec2D GetSize();

private:
	Vec2D size { 0,0 };
	GameMapTile*** mapArray = nullptr;

};