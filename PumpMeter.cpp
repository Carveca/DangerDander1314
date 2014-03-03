//Pumpmeter Source File

#include "stdafx.h"
#include "PumpMeter.h"

PumpMeter::PumpMeter(sf::Sprite* sprite, sf::Vector2f &position)
{
	m_name = "PumpMeter";
	m_position = position;
	m_spriteExtension = sf::Vector2f(0, 65);

	m_sprite = sprite;
	m_sprite->setPosition(position);

}

PumpMeter::~PumpMeter()
{

}

void PumpMeter::Update(int &hpvalue)
{
	m_spriteExtension.x = 5 * hpvalue;

	m_sprite->setTextureRect(sf::IntRect( 0, 0, m_spriteExtension.x, m_spriteExtension.y));


}