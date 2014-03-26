//HighscoreState.cpp

#include "stdafx.h"
#include "HighscoreState.h"
#include "SpriteManager.h"
#include "MusicManager.h"

HighscoreState::HighscoreState()
{
	m_done = false;
}

bool HighscoreState::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_done = false;

	m_spriteManager = spritemanager;
	m_background = m_spriteManager->GetSprite("Highscore.png", 1920, 1080);

	m_musicManager = musicmanager;

	m_musicManager->LoadMusic("screen_music.wav");
	m_musicManager->RepeatON();
	m_musicManager->Play();

	return true;
}

void HighscoreState::Exit()
{

}

bool HighscoreState::Update(float &deltatime)
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

void HighscoreState::Draw(sf::RenderWindow* window)
{
	window->draw(*m_background);
}

std::string HighscoreState::Next()
{
	return m_nextState;
}

bool HighscoreState::IsType(const std::string &type)
{
	return type.compare("HighscoreState") == 0;
}

void HighscoreState::Draw(sf::RenderWindow* window, float &deltatime)
{

}

