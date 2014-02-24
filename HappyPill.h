//HappyPill.h

#pragma once
#include "Powerup.h"


class HappyPill : public Powerup
{
public:
	HappyPill(sf::Sprite sprite, sf::Vector2f position);
	~HappyPill();

	void Update(float elapsedTime);
	void HandleCollision();

protected:
	
};