//MenuState II source file

#include "stdafx.h"
#include "MenuStateII.h"


MenuStateII::MenuStateII()
{
	m_done = false;
}

bool MenuStateII::Enter(SpriteManager* spritemanager)
{
	m_done = false;

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