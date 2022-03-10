#include "CombatObject.h"

CombatObject::~CombatObject()
{
	commands.clear();
	opponent = nullptr;
}

int CombatObject::GetMaxHP()
{
	return hp.max;
}
int CombatObject::GetCurHP()
{
	return hp.cur;
}
int CombatObject::GetMaxMP()
{
	return mp.max;
}
int CombatObject::GetCurMP()
{
	return mp.cur;
}
int CombatObject::GetMaxSTR()
{
	return str.max;
}
int CombatObject::GetCurSTR()
{
	return str.cur;
}
int CombatObject::GetMaxDEF()
{
	return def.max;
}
int CombatObject::GetCurDEF()
{
	return def.cur;
}
int CombatObject::GetMaxSPD()
{
	return spd.max;
}
int CombatObject::GetCurSPD()
{
	return spd.cur;
}
int CombatObject::GetMaxACC()
{
	return acc.max;
}
int CombatObject::GetCurACC()
{
	return acc.cur;
}
int CombatObject::GetMaxEVA()
{
	return eva.max;
}
int CombatObject::GetCurEVA()
{
	return eva.cur;
}


void CombatObject::SetMaxHP(int _hp)
{
	hp.max = _hp;
}
void CombatObject::SetCurHP(int _hp)
{
	hp.cur = _hp;
}
void CombatObject::SetMaxMP(int _mp)
{
	mp.max = _mp;
}
void CombatObject::SetCurMP(int _mp)
{
	mp.cur = _mp;
}
void CombatObject::SetMaxSTR(int _str)
{
	str.max = _str;
}
void CombatObject::SetCurSTR(int _str)
{
	str.cur = _str;
}
void CombatObject::SetMaxDEF(int _def)
{
	def.max = _def;
}
void CombatObject::SetCurDEF(int _def)
{
	def.cur = _def;
}
void CombatObject::SetMaxSPD(int _spd)
{
	spd.max = _spd;
}
void CombatObject::SetCurSPD(int _spd)
{
	spd.cur = _spd;
}
void CombatObject::SetMaxACC(int _acc)
{
	acc.max = _acc;
}
void CombatObject::SetCurACC(int _acc)
{
	acc.cur = _acc;
}
void CombatObject::SetMaxEVA(int _eva)
{
	eva.max = _eva;
}
void CombatObject::SetCurEVA(int _eva)
{
	eva.cur = _eva;
}