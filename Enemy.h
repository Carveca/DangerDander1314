//Enemy header file

#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	void AI();

	virtual int GetPoints();
	virtual int GetAttackPower();


protected:
	int m_points;
	int m_attackPower;

};