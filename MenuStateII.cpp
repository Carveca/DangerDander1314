//MenuState II source file

#include "stdafx.h"
#include "MenuStateII.h"

#include "SpriteManager.h"
#include "MusicManager.h"


MenuStateII::MenuStateII()
{
	m_done = false;
	
}

bool MenuStateII::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_done = false;
	m_selection = 1;
	m_keytimer = 0.0f;

	m_spriteManager = spritemanager;
	m_backGround = m_spriteManager->GetSprite("menuscreen.png", 1920, 1080);
	
	m_musicManager = musicmanager;

	m_musicManager->LoadMusic("screen_music.wav");
	m_musicManager->RepeatON();
	m_musicManager->Play();
	
	cursor.setRadius(50);
	cursorPOS.x = 600;
	cursorPOS.y = 200;
	cursor.setFillColor(sf::Color::Transparent);
	cursor.setOutlineColor(sf::Color::Red);
	cursor.setOutlineThickness(5);

	return true;
}

void MenuStateII::Exit()
{

}

//state loop

bool MenuStateII::Update(float &deltatime)
{
	//std::cout << "MenuII" << std::endl;

	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		m_nextState = "GameStateII";
		m_done = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_nextState = "quit";
		m_done = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_keytimer <= 0.0)
	{
		if(m_selection != 5)
		{
			m_selection += 1;
			cursorPOS.y += 100;
			m_keytimer = 0.2;
		}
		else
		{
			m_selection = 1;
			cursorPOS.y = 200;
			m_keytimer = 0.2;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_keytimer <= 0.0)
	{
		if(m_selection != 1)
		{
			m_selection -= 1;
			cursorPOS.y -= 100;
			m_keytimer = 0.2;
		}
		else
		{
			m_selection = 5;
			cursorPOS.y = 600;
			m_keytimer = 0.2;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if(m_selection == 1)
		{
			m_nextState = "GameStateII";
			m_done = true;
		}
		else if(m_selection == 5)
		{
			m_nextState = "quit";
			m_done = true;
		}
 	}

	m_keytimer -= deltatime;
	if(m_keytimer < -10)
	{
		m_keytimer = 0.0f;
	}
	
	cursor.setPosition(cursorPOS);

	return m_done;
}

void MenuStateII::Draw(sf::RenderWindow* window)
{
	
		window->draw(*m_backGround);
		window->draw(cursor);
	
}

//state switch

std::string MenuStateII::Next()
{
	return m_nextState;
}

bool MenuStateII::IsType(const std::string &type)
{
	return type.compare("MenuStateII") == 0;
}

void MenuStateII::Draw(sf::RenderWindow* window, float &deltatime)
{

}