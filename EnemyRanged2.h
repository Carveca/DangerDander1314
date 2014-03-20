//Enemy ranged protester version header file

#pragma once

#include "Enemy.h"

class EnemyRanged2 : public Enemy
{
public:
	EnemyRanged2(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attacksprite ,sf::Sprite* deathsprite, SoundManager* soundmanager);
	~EnemyRanged2();

	void RangedAttack();
	void Update(float &deltatime, sf::Vector2f refpos);
	void HandleCollision();

	bool GetAttackAnimation();
	bool GetAttacking();
	sf::Vector2f GetDirection();

	sf::Sprite* GetSprite();
	sf::Sprite* GetAttackSprite();
	sf::Sprite* GetDeathSprite();

protected:
	sf::Vector2f m_Direction;

	bool m_isAttacking;
	bool m_attackAnimation;

	FileReader* m_reader;
	SoundManager* m_soundManager;
	sf::Sprite* m_attackSprite;
	sf::Sprite* m_deathSprite;

	int m_attackImageNR;
	float m_attackFrameCounter;
	float m_attackTimer;
};