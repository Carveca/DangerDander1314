//Enemy Mêlée header file

#pragma once
#include "Enemy.h"

class EnemyMelee : public Enemy
{
public:
	EnemyMelee(sf::Sprite* sprite, sf::Vector2f &position, SoundManager* soundmanager);
	~EnemyMelee();

	void MeleeAttack();
	void Update(float &deltatime);
	void HandleCollision();

protected:
	SoundManager* m_soundManager;

	int m_yDirection;
};