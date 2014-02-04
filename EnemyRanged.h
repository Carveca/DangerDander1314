//EnemyRanged.h

#pragma once

#include "Enemy.h"

class EnemyRanged : Public Enemy
{
	EnemyRanged();
	~EnemyRanged();

	void RangedAttack();
	void Update();
	void HandleCollision();

protected:


};