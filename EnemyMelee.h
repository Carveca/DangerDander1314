//Enemy Mêlée header file

#pragma once
#include "Enemy.h"

class EnemyMelee : public Enemy
{
public:
	EnemyMelee(sf::Sprite* sprite, sf::Vector2f &position);
	~EnemyMelee();

	void MeleeAttack();
	void Update(float &deltatime);
	void HandleCollision();

protected:
	int m_yDirection;
};