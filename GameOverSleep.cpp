//game over sleep source file

#pragma once

#include "stdafx.h"
#include "GameOverSleep.h"

#include "SpriteManager.h"
#include "MusicManager.h"

GameOverSleep::GameOverSleep()
{
	m_done = false;
}

bool GameOverSleep::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_done = false;

	m_spriteManager = spritemanager;
	m_backGround = m_spriteManager->GetSprite("game_over_snooze.png", 1920, 1080);


	m_musicManager = musicmanager;
	m_musicManager->LoadMusic("snooze_you_loose.wav");
	m_musicManager->RepeatOFF();
	m_musicManager->Play();
	

	return true;
}

void GameOverSleep::Exit()
{

}

bool GameOverSleep::Update(float &deltatime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_nextState = "MenuStateII";
		m_done = true;
	}


	return m_done;
}

void GameOverSleep::Draw(sf::RenderWindow* window)
{
	window->draw(*m_backGround);
}

std::string GameOverSleep::Next()
{
	return m_nextState;
}


bool GameOverSleep::IsType(const std::string &type)
{
	return type.compare("GameOverSleep") == 0;
}

void GameOverSleep::Draw(sf::RenderWindow* window, float &deltatime)
{

}