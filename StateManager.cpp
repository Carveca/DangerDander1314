//StateManager.cpp

#include "stdafx.h"
#include "State.h"
#include "StateManager.h"
#include "SpriteManager.h"

#include <iostream>

StateManager::StateManager()
{
	m_current = nullptr;

	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Aggressive Bystander");

	m_spriteManager = new SpriteManager;
	m_spriteManager->Initialize("../Sprites/");
}

StateManager::~StateManager()
{
	auto it = m_states.begin();
	while(it!=m_states.end())
	{
		delete (*it);
		++it;
	}
	m_states.clear();

	
	delete m_window;
	m_window = nullptr;
	
}

bool StateManager::Attach(State* state)
{
	m_states.push_back(state);

	if(state=nullptr)
	{
		return false;
	}

	return true;
}

void StateManager::Update(float &deltatime)
{
	if(m_current==nullptr)
	{
		return;
	}
	//Window event
	sf::Event event;
	if(m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_window->close();
		}
	}
	//Update state
	if(m_current->Update(deltatime))
	{
		ChangeState();
		m_current->Enter(this, m_spriteManager);
	}
		
}

void StateManager::Draw()
{
	if(m_current==nullptr)
	{
		return;
	}
	m_window->clear(sf::Color::Black);

	m_current->Draw(m_window);

	m_window->display();
}

void StateManager::SetState(const std::string &type)
{
	for(unsigned int i = 0; i < m_states.size(); i++)
	{
		if(m_states[i]->IsType(type))
		{
			m_current = m_states[i];
			m_current->Enter(this, m_spriteManager);
			return;
		}
	}
}

void StateManager::ChangeState()
{
	std::string next = m_current->Next();

	if(m_current!=nullptr)
	{
		m_current->Exit();
		m_current=nullptr;
	}

	for(unsigned int i=0;i<m_states.size();i++)
	{
		if(m_states[i]->IsType(next))
		{
			m_current=m_states[i];
			m_current->Enter(this, m_spriteManager);
			return;
		}
	}
}

bool StateManager::IsRunning()
{
	return m_current != nullptr;
}
