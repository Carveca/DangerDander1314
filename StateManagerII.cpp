//StateManager II source file

#include "stdafx.h"
#include "StateManagerII.h"
#include "StateII.h"

#include "SpriteManager.h"
#include "MusicManager.h"

StateManagerII::StateManagerII()
{
	m_current = nullptr;

	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Aggressive Bystander");

	m_spriteManager = new SpriteManager;
	m_spriteManager->Initialize("../Sprites/");

	m_musicManager = new MusicManager;
	m_musicManager->Initialize("../Music/");

	m_musicManager->LoadMusic("soundtrack_high_1.wav");
	m_musicManager->Play();
}

StateManagerII::~StateManagerII()
{
	//sprite and music managers


	auto iterator = m_states.begin();
	while(iterator != m_states.end() )
	{
		delete (*iterator);
		++iterator;
	}
}

void StateManagerII::Attach(StateII* state)
{
	m_states.push_back(state);
}

//State Loops

void StateManagerII::Update(float &deltatime)
{
	if(m_current == nullptr)
		return;

	sf::Event event;
	if(m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_window->close();
		}
	}

	if(m_current->Update(deltatime))
	{
		ChangeState();
	}
}

void StateManagerII::Draw()
{
	if(m_current == nullptr)
		return;

	m_window->clear(sf::Color::Black);

	m_current->Draw(m_window);

	m_window->display();

}

//Set States

void StateManagerII::SetState(const std::string &type)
{
	for(unsigned int i = 0; i < m_states.size(); i++)
	{
		if(m_states[i]->IsType(type))
		{
			m_current = m_states[i];
			return;
		}
	}
}

void StateManagerII::ChangeState()
{
	std::string nextState = m_current->Next();

	if(m_current != nullptr)
	{
		m_current->Exit();
		m_current = nullptr;
	}

	if(nextState == "quit")
	{
		m_window->close();
	}

	for(unsigned int i = 0; i < m_states.size(); i++)
	{
		if(m_states[i]->IsType(nextState))
		{
			m_current = m_states[i];
			m_current->Enter(m_spriteManager);
			return;
		}
	}
}

