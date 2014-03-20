//Level Source File

#include "stdafx.h"
#include "Level.h"
#include "SpriteManager.h"

Level::Level()
{
	
}

Level::Level(SpriteManager* spritemanager)
{
	m_name = "Level";

	m_spriteManager = spritemanager;

	/*
	m_streetTopStart			= sf::Vector2f(400	, -1079);
	m_streetBottomStart			= sf::Vector2f(400	, 0);
	m_leftInitialImageStart		= sf::Vector2f(0	, 0);
	m_rightInitialImageStart	= sf::Vector2f(1520	, 0);
	m_leftImageStart			= sf::Vector2f(0	, -1079);
	m_rightImageStart			= sf::Vector2f(1520	, -1079);
	*/

	//placeholder
	m_sprite = m_spriteManager->GetSprite("gamespace1.png", 1920, 1080);

	m_position2 = sf::Vector2f(0, -1079);
	m_sprite2 = m_spriteManager->GetSprite("gamespace2.png", 1920, 1080);

	m_position3 = sf::Vector2f(0, -2158);
	m_sprite3 = m_spriteManager->GetSprite("gamespace3.png", 1920, 1080);

	m_position4 = sf::Vector2f(0, -3237);
	m_sprite4 = m_spriteManager->GetSprite("gamespace4.png", 1920, 1080);

	m_position5 = sf::Vector2f(0, -4316);
	m_sprite5 = m_spriteManager->GetSprite("gamespace5.png", 1920, 1080);

	m_position6 = sf::Vector2f(0, -5395);
	m_sprite6 = m_spriteManager->GetSprite("gamespace6.png", 1920, 1080);

}

Level::~Level()
{

}

void Level::Update(float &deltatime)
{
	m_position.y += 100 * deltatime;		
	if(m_position.y >= 1079.0f)
	{
		m_position.y = -5395;
	}

	m_position2.y += 100 * deltatime;
	if(m_position2.y >= 1079.0f)
	{
		m_position2.y = -5395;
	}
	
	m_position3.y += 100 * deltatime;
	if(m_position3.y >= 1079.0f)
	{
		m_position3.y = -5395;
	}

	m_position4.y += 100 * deltatime;
	if(m_position4.y >= 1079.0f)
	{
		m_position4.y = -5395;
	}

	m_position5.y += 100 * deltatime;
	if(m_position5.y >= 1079.0f)
	{
		m_position5.y = -5395;
	}

	m_position6.y += 100 * deltatime;
	if(m_position6.y >= 1079.0f)
	{
		m_position6.y = -5395;
	}
} 

void Level::Draw(sf::RenderWindow* window)
{
	window->draw(*GetSprite());
	window->draw(*GetSprite2());
	window->draw(*GetSprite3());
	window->draw(*GetSprite4());
	window->draw(*GetSprite5());
	window->draw(*GetSprite6());
}

sf::Sprite* Level::GetSprite2()
{
	m_sprite2->setPosition(m_position2);
	return m_sprite2;
}

sf::Sprite* Level::GetSprite3()
{
	m_sprite3->setPosition(m_position3);
	return m_sprite3;
}

sf::Sprite* Level::GetSprite4()
{
	m_sprite4->setPosition(m_position4);
	return m_sprite4;
}

sf::Sprite* Level::GetSprite5()
{
	m_sprite5->setPosition(m_position5);
	return m_sprite5;
}

sf::Sprite* Level::GetSprite6()
{
	m_sprite6->setPosition(m_position6);
	return m_sprite6;
}