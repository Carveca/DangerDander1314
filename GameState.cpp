//GameState.cpp

#include "stdafx.h"
#include "GameState.h"

#include "StateManager.h"
#include "SpriteManager.h"
#include "EntityManager.h"

#include "SpawnerAOEenemy.h"

#include "Player.h"
#include "Level.h"

#include <iostream>

GameState::GameState()
{
	m_done = false;
}

bool GameState::Enter(StateManager* stateManager, SpriteManager* spriteManager)
{
	m_direction.x = 0;
	m_direction.y = 0;
	m_angle = 0;

	m_stateManager = stateManager;
	m_spriteManager = spriteManager;

	m_next_state = "GameState";

	//m_entityManager = new EntityManager;
	m_spawnerAOEenemy = new SpawnerAOEenemy(m_spriteManager->GetSprite("AOE.png", 1024, 128), m_spriteManager->GetSprite("aoe_attack.png", 256, 256), sf::Vector2f(400, -100) );

	m_player			= new Player(m_spriteManager->GetSprite("player_weapon.png", 2048, 256), sf::Vector2f(950, 540), m_spriteManager->GetSprite("player_attack.png", 1024, 256) );
	m_levelTop			= new Level( m_spriteManager->GetSprite("new_gamespace.png", 1920, 1080), sf::Vector2f(0, 0) );
	m_levelBottom		= new Level( m_spriteManager->GetSprite("new_gamespace.png", 1920, 1080), sf::Vector2f(0, -1079) );

	return true;
}

void GameState::Exit()
{
	//Level
	if(m_levelTop != nullptr)
	{
		delete m_levelTop;
		m_levelTop = nullptr;
	}
	if(m_levelBottom != nullptr)
	{
		delete m_levelBottom;
		m_levelBottom = nullptr;
	}
	
	//player
	if(m_player != nullptr)
	{
		delete m_player;
		m_player = nullptr;
	}

	//entitymanager
	if(m_entityManager != nullptr)
	{
		delete m_entityManager;
		m_entityManager = nullptr;
	}
	//aoespawner
	if(m_spawnerAOEenemy != nullptr)
	{
		delete m_spawnerAOEenemy;
		m_spawnerAOEenemy = nullptr;
	}

	
	m_done = true;
}


bool GameState::Update(float &deltatime)
{
	std::cout<<"GameState"<<std::endl;
	
	Input();

	//Player
	m_player->Update(m_angle, m_direction, deltatime);

	if(m_player->GetAttacking() == true) //&& m_attackContainer.size() < 1)
		{
			//std::cout << "Attack!" << std::endl;			
			sf::Vector2f attackPOS = m_player->GetPosition();
			if(m_angle == 0) //up
				attackPOS += sf::Vector2f(0, -128);
			else if(m_angle == 45)//up right
				attackPOS += sf::Vector2f(120, -120);
			else if(m_angle == 90)//right
				attackPOS += sf::Vector2f(128, 0);
			else if(m_angle == 135)//down right
				attackPOS += sf::Vector2f(120, 120);
			else if(m_angle == 180)//down
				attackPOS += sf::Vector2f(0, 128);
			else if(m_angle == 225)//down left
				attackPOS += sf::Vector2f(-120, 120);
			else if(m_angle == 270)//left
				attackPOS += sf::Vector2f(-128, 0);
			else if(m_angle == 315)//up left
				attackPOS += sf::Vector2f(-120, -120);

			//m_attackContainer.push_back( new PlayerAttack(AttackSprite , attackPOS, m_player->GetWeaponSize() ) );
		}


	//Level
	m_levelTop->Update(deltatime);
	m_levelBottom->Update(deltatime);
	//Aoe enemy spawn
	m_spawnerAOEenemy->Update(deltatime);
	if(m_spawnerAOEenemy->GetSpawnState())
	{
		m_entityManager->AddEnemyAOE(m_spawnerAOEenemy->Spawn());
	}
	//EntityManager
	m_entityManager->Update(m_angle, m_direction, deltatime);
		

	//end
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_next_state = "MenuState";
		Exit();
	}

	return m_done;
}

void GameState::Draw(sf::RenderWindow* window)
{
	//Level
	window->draw(*m_levelTop->GetSprite());
	window->draw(*m_levelBottom->GetSprite());
	//EntityManager
	m_entityManager->Draw(window);
	//Player
	window->draw(*m_player->GetSprite());

}

std::string GameState::Next()
{
	return m_next_state;
}

bool GameState::IsType(const std::string &type)
{
	return type.compare("GameState")==0;
}

void GameState::Input()
{
	//keyboard input
	//sf::Event event;
	//m_stateManager->m_window->pollEvent(event);

	

	//Attack Input
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
	{
		m_player->Attack();
	}

	//Movement Input
	m_direction.x = 0;
	m_direction.y = 0;			
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction.x = -1;
		m_direction.y = -1;
		m_angle = 315;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction.x = 1;
		m_direction.y = -1;
		m_angle = 45;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction.y = -1;
		m_angle = 0;
	}		
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction.x = -1;
		m_direction.y = 1;
		m_angle = 225;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction.x = 1;
		m_direction.y = 1;
		m_angle = 135;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction.y = 1;
		m_angle = 180;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction.x = -1;
		m_angle = 270;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction.x = 1;
		m_angle = 90;
	}


}