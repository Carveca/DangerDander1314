//Player Attack Header File

#pragma once

#include "InteractiveObject.h"

class PlayerAttack : public InteractiveObject
{
public:
	PlayerAttack(sf::Sprite sprite ,sf::Vector2f position, int size);
	~PlayerAttack();

	void Update(float elapsedTime);

	bool Dead();

private:
	float m_life;
	bool m_dead;
};