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

	m_spriteManager = spritemanager;
	m_backGround = m_spriteManager->GetSprite("menuscreen.png", 1920, 1080);


	m_musicManager = musicmanager;

	m_musicManager->LoadMusic("screen_music_1.wav");
	m_musicManager->RepeatON();
	m_musicManager->Play();


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


	return m_done;
}

void MenuStateII::Draw(sf::RenderWindow* window)
{

	window->draw(*m_backGround);

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