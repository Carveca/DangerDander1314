//Player header file

#pragma once

#include "Character.h"

class Player : public Character
{
	friend class Engine;
public:
	Player(sf::Sprite sprite, sf::Vector2f position);
	~Player();
	
	void Initialize();
	void Cleanup();	
	void Update(float angle, sf::Vector2f direction, float elapsedtime);
	void HandleCollision();
	void Attack();
	void WeaponStick();
	void ChangeHP(int value);

	int GetWeaponSize();
	
	float GetAttackTimer();

	bool GetAttacking();

	sf::Sprite GetSprite();
		
	//   power ups on 1,2 and 3?

protected:
	float m_attackTimer;
	float m_drainTimer;
	float m_powerupTimer;

	int m_weaponSize;
	int m_hpDrain;
	
	bool m_isAttacking;

	int m_happypillcontainer;
	int m_bluecowcontainer;
};