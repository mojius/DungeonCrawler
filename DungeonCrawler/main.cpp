#include "util.h"
#include <iostream>
#include "GameMap.h"
#include "Player.h"
#include <string>
#include <stdlib.h>
#include <random>
#include "BattleManager.h"
#include "Enemy.h"

int main()
{
	GameMap mapOne("C:\\repos\\projects\\dungeon-crawler\\DungeonCrawler\\DungeonCrawler\\map.txt", false);
	std::cout << "Welcome to Dungeon Crawler version 1e^-4.\n";

	Player p(mapOne, { 0,0 }, Player::Orientation::SOUTH);

	char direction;


	//	//Battle code begins.
	//	int playerHP = 5;
	int random = 0;
	while (true)
	{
		random = (rand() % 100) + 1;
		if (random < 16)
		{

			Skeleton sk;
			BattleManager bm(p, sk);



		}


		p.printGameMap();

		std::cout << "Pick a direction for the player to move to. (WASD)";
		std::cin >> direction;
		if (96 < direction && direction < 123) direction -= 32;
		switch (direction)
		{
		case 'W':
			p.move(Player::Orientation::NORTH);
			break;
		case 'A':
			p.move(Player::Orientation::WEST);
			break;
		case 'S':
			p.move(Player::Orientation::SOUTH);
			break;
		case 'D':
			p.move(Player::Orientation::EAST);
			break;

		}



		
	}
	return 0;
}