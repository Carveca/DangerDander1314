//MenuState.cpp

#include "MenuState.h"
#include <iostream>

MenuState::MenuState()
{
	m_done=false;
}

bool MenuState::Enter()
{
	return true;
}

void MenuState::Exit()
{
	//Cleanup goes here
}

bool MenuState::Update(float deltatime)
{
	std::cout<<"MenuState"<<std::endl;
	std::cin.ignore(1024, '\n');
	std::cin.get();
	m_next_state="GameState";
	return m_done;
}

void MenuState::Draw()
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