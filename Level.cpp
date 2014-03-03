//Level Source File

#include "stdafx.h"
#include "Level.h"

Level::Level()
{

}

Level::Level(sf::Sprite* sprite, sf::Vector2f &position)
{
	m_name = "Level";

	m_position = position;

	m_sprite = sprite;

}

Level::~Level()
{

}

void Level::Update(float &deltatime)
{
	m_position.y += 100 * deltatime;
		
	if(m_position.y >= 1079.0f)
	{
		m_position.y = -1079.0f;
	}

	m_sprite->setPosition(m_position);
}