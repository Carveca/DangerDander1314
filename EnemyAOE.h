//EnemyAOE.h

#pragma once

#include "Enemy.h"

class EnemyAOE : Public Enemy
{
	EnemyAOE();
	~EnemyAOE();

	AOEAttack();
	void Update();
	void HandleCollision();

protected:


};