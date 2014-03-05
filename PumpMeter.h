//PumpMeter header

#pragma once

#include "Entity.h"

class PumpMeter : public Entity
{
public:
	PumpMeter(sf::Sprite* pumpSprite, sf::Sprite* indicatorSprite, sf::Sprite* indicatorEffectSprite, sf::Sprite* leftWarningSprite, sf::Sprite* rightWarningSprite, sf::Vector2f &position);
	~PumpMeter();

	void Update(int hpvalue);


public:
	sf::Vector2f m_startPOS;

	sf::Sprite* m_indicatorSprite;
	sf::Sprite* m_indicatorEffectSprite;
	sf::Sprite* m_leftWarningSprite;
	sf::Sprite* m_rightWarningSprite;



};