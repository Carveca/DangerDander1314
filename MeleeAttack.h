//MeleeAttack.h

#pragma once

#include "InteractiveObject.h"

class Player;

class MeleeAttack : public InteractiveObject
{
public:
	MeleeAttack(sf::Sprite* sprite ,sf::Vector2f position);
	~MeleeAttack();

	void Update(float &elapsedTime);
	void HandleCollision();

	//bool Dead();

private:
	float m_life;
	//bool m_dead;

	Player* m_player;
};