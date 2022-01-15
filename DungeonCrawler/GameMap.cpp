#include <iostream>
#include <fstream>
#include "GameMap.h"

//TODO: Error checking, especially with the file.
GameMap::GameMap(std::string dir, bool bordersAreExitsNotWalls) 
{
	int colCount = 0;
	int rowCount = 0;

	GameMapTile*** tileData;

	std::ifstream file(dir);
	if (file.is_open())
	{

		while (!file.eof())
		{

			int c = file.get();

			switch (c)
			{
			case '\n':
				rowCount++;
				break;
			default:
				colCount++;
				break;
			}

		}

		rowCount++;
		colCount /= rowCount;

		//Draw this.

		tileData = new GameMapTile **[rowCount];
		for (int i = 0; i < rowCount; i++)
			tileData[i] = new GameMapTile * [colCount];

		file.clear();
		file.seekg(0);

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount + 1; j++)
			{
				int c = file.get();

				switch (c)
				{
				case '=':
					tileData[i][j] = new GameMapTile(TileState::SOLID);
					break;
				case '-':
					tileData[i][j] = new GameMapTile(TileState::AIR);
					break;
				case 'v':
					tileData[i][j] = new GameMapTile(TileState::ENTRANCE);
					break;
				case '^':
					tileData[i][j] = new GameMapTile(TileState::EXIT);
					break;
				}

			}
		}
		file.close();
		this->mapArray = tileData;
		this->size = Vec2D(colCount, rowCount);
	}

}


GameMap::TileState GameMap::GameMapTile::GetTileState()
{
	return this->state;
}

GameMap::GameMapTile::GameMapTile(TileState p_state) : state(p_state) {}

std::vector<GameObject*>* GameMap::GameMapTile::GetObjectList()
{
	return &(this->objects);
}

Vec2D GameMap::GetSize()
{
	return this->size;
}

GameMap::GameMapTile*** GameMap::GetMapArray()
{
	return this->mapArray;
}