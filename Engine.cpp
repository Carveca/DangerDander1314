//Engine source file

#include "stdafx.h"
#include "Engine.h"

#include "SpriteManager.h"
#include "Player.h"
#include "EnemyMelee.h"
#include "Collider.h"
#include "CollisionManager.h"

#include "Entity.h"

#include <iostream>

Engine::Engine()
{
	m_direction.x = 0.0f;
	m_direction.y = 0.0f;

	m_angle = 0.0f;
}

Engine::~Engine()
{

}

bool Engine::Initialize()
{
	m_window.create(sf::VideoMode(1920, 1080), "Dangerous Dander");
		
	m_collisionManager = new CollisionManager;

	m_sprite_manager = new SpriteManager;
	m_sprite_manager->Initialize("../Sprites/");

	/*
	m_sprite_manager->LoadSprite("gamespacecity.png", "Level", 0, 0, 1920, 2160, 1, 1);
	LevelTexture = m_sprite_manager->GetTextures()["LevelTexture"];
	LevelSprite = m_sprite_manager->GetSprites()["Level"];
	LevelSprite.setTexture(LevelTexture);
	sf::Vector2f levelPOS; levelPOS.x = 0.0f; levelPOS.y = 0.0f;
	m_level = new Entity(LevelSprite, levelPOS);
	*/

	m_sprite_manager->LoadSprite("player_move.png", "Player", 0, 0, 2048, 256, 1, 1);
	PlayerTexture = m_sprite_manager->GetTextures()["PlayerTexture"];
	PlayerSprite = m_sprite_manager->GetSprites()["Player"];
	PlayerSprite.setTexture(PlayerTexture);

	sf::Vector2f playerPOS;	playerPOS.x = 400.0f; playerPOS.y = 200.0f;
	m_player = new Player(PlayerSprite, playerPOS);
	
	m_sprite_manager->LoadSprite("AOE.png", "EnemyMelee", 0, 0, 1024, 128, 1, 1);
	EnemyMeleeTexture = m_sprite_manager->GetTextures()["EnemyMeleeTexture"];
	EnemyMeleeSprite = m_sprite_manager->GetSprites()["EnemyMelee"];
	EnemyMeleeSprite.setTexture(EnemyMeleeTexture);

	sf::Vector2f enemyPOS; enemyPOS.x = 400; enemyPOS.y = 500;
	sf::Vector2f enemyPOS2; enemyPOS2.x = 600; enemyPOS2.y = 600;
	m_enemy = new EnemyMelee(EnemyMeleeSprite, enemyPOS);
	m_enemy2 = new EnemyMelee(EnemyMeleeSprite, enemyPOS2);
	
			
	return true;
}

void Engine::Cleanup()
{
	m_player->Cleanup();
	m_enemy->Cleanup();
}

void Engine::Run()
{
	while(m_window.isOpen())
	{				
		m_elapsedTime = m_clock.restart().asSeconds();	
					
		sf::Event event;			
		while(m_window.pollEvent(event))
		{				
			if(event.type == sf::Event::Closed)
			{
				m_window.close();
			}						
		}

		//Attack
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
		{
			m_player->Attack();
		}
		//Movement
		m_direction.x = 0.0f;
		m_direction.y = 0.0f;			
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
		
		//Attack, should happen in player update
		if(m_player->GetAttackTimer() == 0.5f)
		{
			std::cout << "Attack!" << std::endl;
		}
				
		//Update
		m_player->Update(m_angle, m_direction, m_elapsedTime);	
		m_enemy->Update(m_elapsedTime);
		m_enemy2->Update(m_elapsedTime);

		//Collision
		m_collisionManager->Add(m_player);
		m_collisionManager->Add(m_enemy);
		m_collisionManager->Add(m_enemy2);

		m_collisionManager->CheckCollision();
		
		m_window.clear(sf::Color(0x11, 0x11, 0x11, 0xff));
		
		m_window.draw(m_player->GetSprite());
		m_window.draw(m_enemy->GetSprite());
		m_window.draw(m_enemy2->GetSprite());
		m_window.display();				
		
	}
}
