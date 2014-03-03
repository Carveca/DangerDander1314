//MenuState.cpp

#include "stdafx.h"
#include "MenuState.h"

#include "Level.h"
#include "SpriteManager.h"
#include "StateManager.h"
#include "SpriteManager.h"

#include <iostream>

MenuState::MenuState()
{
	
	m_done=false;
}

bool MenuState::Enter(StateManager* stateManager, SpriteManager* spriteManager) 
{
	m_stateManager = stateManager;
	m_spriteManager = spriteManager;

	m_next_state = "MenuState";

	
	

	return true;
}

void MenuState::Exit()
{
	

	

	m_done = true;
}

bool MenuState::Update(float &deltatime)
{
	std::cout << "Menu" << std::endl;
	
	//sf::Event event;
	//m_stateManager->m_window->pollEvent(event);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		m_next_state = "GameState";
		Exit();		
	}
	
	return m_done;
}

void MenuState::Draw(sf::RenderWindow* window)
{	

	

}

std::string MenuState::Next()
{
	return m_next_state;
}

bool MenuState::IsType(const std::string &type)
{
	return type.compare("MenuState")==0;
}