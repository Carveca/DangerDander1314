//EnemyAOE.h

#pragma once

#include "Enemy.h"
#include "AOEattack.h"

class EnemyAOE : public Enemy
{
public:
	EnemyAOE();
	EnemyAOE(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attacksprite, SoundManager* soundmanager);
	~EnemyAOE();

	void Attack();
	void Update(float &deltatime);
	void HandleCollision();

	AOEattack* GetAttack();


protected:
	int m_yDirection, m_xDirection;

	float m_moveTimer;

	AOEattack* m_attack;

	SoundManager* m_soundManager;
};