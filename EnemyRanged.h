//EnemyRanged.h

#pragma once

#include "Enemy.h"

class EnemyRanged : public Enemy
{
	EnemyRanged();
	~EnemyRanged();

	void RangedAttack();
	void Update();
	void HandleCollision();

protected:


};