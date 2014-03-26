//CreditsState.cpp

#include "stdafx.h"
#include "CreditsState.h"
#include "SpriteManager.h"
#include "MusicManager.h"

CreditsState::CreditsState()
{
	m_done = false;
}

bool CreditsState::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_done = false;

	m_spriteManager = spritemanager;
	m_background = m_spriteManager->GetSprite("menuscreen.png", 1920, 1080);

	m_musicManager = musicmanager;

	m_musicManager->LoadMusic("screen_music.wav");
	m_musicManager->RepeatON();
	m_musicManager->Play();

	return true;
}

void CreditsState::Exit()
{

}

bool CreditsState::Update(float &deltatime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_nextState = "MenuStateII";
		m_done = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_nextState = "quit";
		m_done = true;
	}

	return m_done;
}

void CreditsState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_background);
}

void CreditsState::Draw(sf::RenderWindow* window, float &deltatime)
{

}

std::string CreditsState::Next()
{
	return m_nextState;
}

bool CreditsState::IsType(const std::string &type)
{
	return type.compare("CreditsState") == 0;
}
