//Enemy Mêlée header file

#pragma once
#include "Enemy.h"

class EnemyMelee : public Enemy
{
public:
	EnemyMelee(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attackSprite, sf::Sprite* deathsprite, SoundManager* soundmanager);
	~EnemyMelee();

	void MeleeAttack();
	void Update(float &deltatime, sf::Vector2f refpos);
	void HandleCollision();

	bool GetAttacking();
	sf::Vector2f GetDirection();
	bool GetAttackAnimation();

	sf::Sprite* GetSprite();
	sf::Sprite* GetAttackSprite();


protected:
	sf::Vector2f m_Direction;

	bool m_isAttacking;
	bool m_attackAnimation;
	
	sf::Sprite* m_attackSprite;
	float m_attackFrameCounter;
	int m_attackImageNR;

	float m_attackTimer;

	SoundManager* m_soundManager;
	FileReader* m_reader;

};