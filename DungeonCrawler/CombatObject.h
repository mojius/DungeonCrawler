#pragma once

#include "GameObject.h"
#include <vector>
#include <string>
#include "Equipment.h"

class IBattleCommand;

class CombatObject: public GameObject
{

protected:
	CombatObject* opponent;
	std::vector<IBattleCommand*> commands;
	friend class BattleManager;
	virtual void CombatThink() = 0;
	~CombatObject();

	struct { int max, cur; } hp;
	struct { int max, cur; } mp;
	struct { int max, cur; } str;
	struct { int max, cur; } def;
	struct { int max, cur; } spd;
	struct { int max, cur; } acc;
	struct { int max, cur; } eva;


public:

	std::string name;
	bool fleeSuccess;
	const bool monster;

	// idk what to do 
	Equipment* head = nullptr;
	Equipment* chest = nullptr;
	Equipment* rhand = nullptr;
	Equipment* lhand = nullptr;
	Equipment* accessory = nullptr;

	int GetMaxHP();
	int GetCurHP();
	int GetMaxMP();
	int GetCurMP();
	int GetMaxSTR();
	int GetCurSTR();
	int GetMaxDEF();
	int GetCurDEF();
	int GetMaxSPD();
	int GetCurSPD();
	int GetMaxACC();
	int GetCurACC();
	int GetMaxEVA();
	int GetCurEVA();

	void SetMaxHP(int _hp);
	void SetCurHP(int _hp);
	void SetMaxMP(int _mp);
	void SetCurMP(int _mp);
	void SetMaxSTR(int _str);
	void SetCurSTR(int _str);
	void SetMaxDEF(int _def);
	void SetCurDEF(int _def);
	void SetMaxSPD(int _spd);
	void SetCurSPD(int _spd);
	void SetMaxACC(int _acc);
	void SetCurACC(int _acc);
	void SetMaxEVA(int _eva);
	void SetCurEVA(int _eva);

};

