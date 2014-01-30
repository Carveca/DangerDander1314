//Enemy header file

#pragma once

#include "Character.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	void AI();

	int GetPoints();
	int GetAttackPower();


protected:
	int m_points;
	int m_attack_power;

};