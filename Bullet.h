//Bullet.h

#pragma once

#include "InteractiveObject.h"

class Bullet : public InteractiveObject
{
public:
	Bullet();
	Bullet(sf::Sprite* sprite, sf::Vector2f position, sf::Vector2f direction, SoundManager* soundmanager );
	~Bullet();

	void Update(float elapsedTime);
	void HandleCollision();

	float GetLife();

protected:
	sf::Vector2f m_Direction;

	SoundManager* m_soundManager;

	float m_bulletLife;
};