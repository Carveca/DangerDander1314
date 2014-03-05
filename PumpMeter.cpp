//Pumpmeter Source File

#include "stdafx.h"
#include "PumpMeter.h"

PumpMeter::PumpMeter(sf::Sprite* pumpSprite, sf::Sprite* indicatorSprite, sf::Sprite* indicatorEffectSprite, sf::Sprite* leftWarningSprite, sf::Sprite* rightWarningSprite, sf::Vector2f &position)
{
	m_name = "PumpMeter";
	m_position = position;

	//Bar Sprite
	m_sprite = pumpSprite;
	m_sprite->setPosition(position);

	//Warnings
	m_leftWarningSprite = leftWarningSprite;
	m_leftWarningSprite->setPosition(position);

	m_rightWarningSprite = rightWarningSprite;
	m_rightWarningSprite->setPosition(position);

	//Indicator
	m_startPOS = sf::Vector2f(position + sf::Vector2f(151, 60) + sf::Vector2f(-35, 0));

	m_indicatorSprite = indicatorSprite;
	m_indicatorSprite->setPosition(m_startPOS);

	m_indicatorEffectSprite = indicatorEffectSprite;
	m_indicatorEffectSprite->setPosition(m_startPOS + sf::Vector2f(-40, -28));


}

PumpMeter::~PumpMeter()
{

}

void PumpMeter::Update(int hpvalue)
{
	m_indicatorSprite->setPosition(m_startPOS + sf::Vector2f( 5 * hpvalue, 0));

	m_indicatorEffectSprite->setPosition(m_indicatorSprite->getPosition() + sf::Vector2f(-40, -28));

}