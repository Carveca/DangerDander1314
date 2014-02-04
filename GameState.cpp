//GameState.cpp

#include "GameState.h"
#include <iostream>

GameState::GameState()
{
	m_done=false;
}

bool GameState::Enter()
{
	return true;
}

bool GameState::Update(float deltatime)
{
	std::cout<<"GameState"<<std::endl;
	std::cin.ignore(1024, '\n');
	std::cin.get();
	m_next_state="MenuState";
	return m_done;
}

void GameState::Draw()
{

}

std::string GameState::Next()
{
	return m_next_state;
}

bool GameState::IsType(const std::string &type)
{
	return type.compare("GameState")==0;
}