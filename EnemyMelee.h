//Enemy Mêlée header file

#pragma once
#include "Enemy.h"

class EnemyMelee : public Enemy
{
public:
	EnemyMelee(sf::Sprite* sprite, sf::Vector2f &position);
	~EnemyMelee();

	void MeleeAttack();
	void Update(float &deltatime, sf::Vector2f refpos);
	void HandleCollision();

	bool GetAttacking();
	sf::Vector2f GetDirection();
protected:
	sf::Vector2f m_Direction;

	bool m_isAttacking;
	bool m_attackAnimation;

	float m_attackTimer;
};