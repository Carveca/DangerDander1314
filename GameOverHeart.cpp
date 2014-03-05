//game over heart attack source file

#pragma once

#include "stdafx.h"
#include "GameOverHeart.h"

#include "SpriteManager.h"
#include "MusicManager.h"

GameOverHeart::GameOverHeart()
{
	m_done = false;
}

bool GameOverHeart::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_done = false;

	m_spriteManager = spritemanager;
	m_backGround = m_spriteManager->GetSprite("game_over_heartattack.png", 1920, 1080);

	m_musicManager = musicmanager;
	m_musicManager->LoadMusic("soundtrack_death_screen_1.wav");
	m_musicManager->Play();
	

	return true;
}

void GameOverHeart::Exit()
{

}

bool GameOverHeart::Update(float &deltatime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_nextState = "MenuStateII";
		m_done = true;
	}

	return m_done;
}

void GameOverHeart::Draw(sf::RenderWindow* window)
{
	window->draw(*m_backGround);
}

std::string GameOverHeart::Next()
{
	return m_nextState;
}


bool GameOverHeart::IsType(const std::string &type)
{
	return type.compare("GameOverHeart") == 0;
}