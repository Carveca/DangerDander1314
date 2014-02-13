//PumpMeter header

#pragma once

#include "Entity.h"

class PumpMeter : public Entity
{
public:
	PumpMeter(sf::Sprite sprite, sf::Vector2f position);
	~PumpMeter();

	void Update(int hpvalue);


private:
	sf::Vector2f m_spriteExtension;
};