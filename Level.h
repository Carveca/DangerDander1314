//Level Header File

#pragma once

#include "Entity.h"

class Level : public Entity
{
public:
	Level(sf::Sprite sprite, sf::Vector2f position);
	~Level();

	void Update(float elapsedTime);


private:
	

};