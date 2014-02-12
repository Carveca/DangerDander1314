//Player header file

#pragma once

#include "Character.h"

class PlayerAttack;

class Player : public Character
{
public:
	Player(sf::Sprite sprite, sf::Vector2f position);
	~Player();
	
	void Initialize();
	void Cleanup();	
	void Update(float angle, sf::Vector2f direction, float elapsedtime);
	void HandleCollision();
	void Attack();
	void WeaponStick();
	
	float GetAttackTimer();

	sf::Sprite GetSprite();
		
	//   power ups on 1,2 and 3.

private:
	float m_attackTimer;
	int m_weaponSize;

	PlayerAttack* m_playerAttack;
};