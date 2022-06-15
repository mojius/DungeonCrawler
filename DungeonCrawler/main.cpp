#include "util.h"
#include <iostream>
#include "GameMap.h"
#include "Player.h"
#include "Item.h"
#include <string>
#include <stdlib.h>
#include <random>
#include "BattleManager.h"
#include "Enemy.h"

int main()
{
	std::cout << "Welcome to Dungeon Crawler version 1e^-4.\n";

	Item i("C:\\source\\repos\\C++\\DungeonCrawler\\Items\\torch.json");
	GameMap mapOne("C:\\repos\\projects\\dungeon-crawler\\DungeonCrawler\\DungeonCrawler\\map.txt", false);


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


		p.PrintGameMap();

		std::cout << "Pick a direction for the player to move to. (WASD)";
		std::cin >> direction;
		if (96 < direction && direction < 123) direction -= 32;
		switch (direction)
		{
		case 'W':
			p.Move(Player::Orientation::NORTH);
			break;
		case 'A':
			p.Move(Player::Orientation::WEST);
			break;
		case 'S':
			p.Move(Player::Orientation::SOUTH);
			break;
		case 'D':
			p.Move(Player::Orientation::EAST);
			break;

		}



		
	}
	return 0;
}