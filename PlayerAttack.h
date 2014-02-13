//Player Attack Header File

#pragma once

#include "InteractiveObject.h"

class PlayerAttack : public InteractiveObject
{
public:
	PlayerAttack(sf::Vector2f position, int size);
	~PlayerAttack();

	void Update(float elapsedTime);


private:
	float m_life;
};