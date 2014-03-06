//Bullet.h

#pragma once

#include "InteractiveObject.h"

class Bullet : public InteractiveObject
{
public:
	Bullet();
	Bullet(sf::Sprite* sprite, sf::Vector2f position, sf::Vector2f direction);
	~Bullet();

	void Update(float elapsedTime);
	void HandleCollision();

protected:
	sf::Vector2f m_Direction;
};