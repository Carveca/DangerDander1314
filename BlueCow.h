//BlueCow.h

#pragma once
#include "Powerup.h"

class BlueCow : public Powerup
{
public:
	BlueCow(sf::Sprite sprite, sf::Vector2f position);
	~BlueCow();

	void Update(float elapsedTime);
	void HandleCollision();

protected:

};