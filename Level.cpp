//Level Source File

#include "stdafx.h"
#include "Level.h"

Level::Level(sf::Sprite sprite, sf::Vector2f position)
{
	m_name = "Level";
	m_position = position;
	m_sprite = sprite;

	m_frameCounter = 0;
	m_imageNR = 0;
	m_extension = sf::Vector2f(0.0, 0.0);
	
}

Level::~Level()
{

}

void Level::Update(float elapsedTime)
{
	m_position.y += 0 * elapsedTime;
		
	if(m_position.y >= 1080)
		m_position.y = -1080;

	m_sprite.setPosition(m_position);
}