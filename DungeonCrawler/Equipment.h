#pragma once
#include "Item.h"
#include <string>

class Equipment : public Item
{
	enum Slot
	{
		RHAND,
		LHAND,
		HEAD,
		BODY,
		ACC
	};
	
	std::string name = "";
	bool equipped = false;
	int hpBonus = 0;
	int mpBonus = 0;
	int strBonus = 0;
	int defBonus = 0;
	int spdBonus = 0;
	int accBonus = 0;
	int evaBonus = 0;

	Equipment(int _hpBonus, int _mpBonus, int _strBonus, int _defBonus, int _spdBonus, int _accBonus, int _evaBonus) 
		: hpBonus(_hpBonus), mpBonus(_mpBonus), strBonus(_strBonus), 
		defBonus(_defBonus), spdBonus(_spdBonus), accBonus(_accBonus), evaBonus(_evaBonus)
	{};

};

class Weapon : public Equipment
{
	enum WeaponType
	{
		SWORD
	};
	std::string name = "";
	int WeaponATK = 0;
};