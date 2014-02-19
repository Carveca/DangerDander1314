//AOEattack header file

#pragma once

#include "InteractiveObject.h"

class AOEattack : public InteractiveObject
{
public:
	AOEattack();
	AOEattack(sf::Sprite sprite, sf::Vector2f position);
	~AOEattack();

	void Update(sf::Vector2f position);
	
protected:

};