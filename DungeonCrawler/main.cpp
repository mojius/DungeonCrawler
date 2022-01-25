#include "util.h"
#include <iostream>
#include "GameMap.h"
#include "Player.h"
#include <string>
#include <stdlib.h>
#include <random>
#include "BattleManager.h"

int main()
{


	GameMap mapOne("C:\\Users\\Mojius\\Documents\\Downloads\\test.txt", false);
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
			BattleManager* bm = new BattleManager(p, 
//			int skeletonHP = 1;
//			bool battleEnded = false;
//
//			int d = 0;
//			std::cout << "A skeleton appears!\n";
//
//			while (!battleEnded)
//			{
//
//
//				//Encapsulate! This should be the player's Think() function -- and how the actions should be arranged and stored is hotly contested. It ain't easy!
//				std::cout << "What will you do?\n1 for attack\n2 for flee\n";
//				std::cin.ignore();
//				d = getchar();
//				d -= 48;
//				int rollRand = 0;
//				switch (d)
//				{
//				case 1:
//					std::cout << "Player attacks!\n";
//					rollRand = (rand() % 6) + 1;
//					if (rollRand > 4)
//					{
//						std::cout << "The skeleton takes damage!\n";	
//						skeletonHP--;
//						if (skeletonHP < 1)
//						{
//							battleEnded = true;
//							std::cout << "Battle won!\n";
//							break;
//						}
//
//					}
//					else if (rollRand < 4) std::cout << "But Player missed!\n";
//					break;
//				case 2:
//					std::cout << "Player tries to flee!\n";
//					rollRand = (rand() % 6) + 1;
//					if (rollRand > 4)
//					{
//						std::cout << "Player got away!\n";
//						battleEnded = true;
//					}
//					break;
//				default:
//					std::cout << "That is not a command!\n";
//					continue;
//				}
//
//				if (battleEnded)
//					break;
//
//				std::cout << "The skeleton attacks!\n";
//				if (rand() % 6 + 1 > 4)
//				{
//					playerHP--;
//					std::cout << "Player takes damage!\n";
//				}
//				else std::cout << "But it missed!\n";
//
//				if (playerHP < 1)
//				{
//					std::cout << "You have died, game over!\n";
//					exit(0);
//				}
//			}
//		}
//
////Battle code ends.

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