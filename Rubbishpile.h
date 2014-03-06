//Rubbishpile.h

#pragma once

#include "InteractiveObject.h"

class Rubbishpile : public InteractiveObject
{
public:
	Rubbishpile(sf::Sprite* sprite, sf::Vector2f &position);
	~Rubbishpile();

	void Update(float &deltatime);
	void HandleCollision();

};