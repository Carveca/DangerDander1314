//Engine source file

#include "stdafx.h"
#include "Engine.h"


#include "Player.h"
#include "PlayerAttack.h"
#include "PumpMeter.h"
#include "EnemyMelee.h"
#include "EnemyAOE.h"
#include "Level.h"

#include "Collider.h"
#include "CollisionManager.h"
#include "SpriteManager.h"


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
	sf::Clock initTimer;

	m_window.create(sf::VideoMode(1920, 1080), "Dangerous Dander");
		
	m_collisionManager = new CollisionManager;

	m_sprite_manager = new SpriteManager;
	m_sprite_manager->Initialize("../Sprites/");

	//Level
	m_sprite_manager->LoadSprite("new_gamespace.png", "Level", 0, 0, 1920, 1080, 1, 1);
	LevelTexture = m_sprite_manager->GetTextures()["LevelTexture"];
	LevelSprite = m_sprite_manager->GetSprites()["Level"];
	LevelSprite.setTexture(LevelTexture);
	
	std::cout << initTimer.restart().asSeconds() << std::endl;

	sf::Vector2f LevelPos = sf::Vector2f(0.0f, -1080.0f);
	m_level_top = new Level(LevelSprite, LevelPos);
	sf::Vector2f LevelPos2 = sf::Vector2f(0.0f, 0.0f);
	m_level_bottom = new Level(LevelSprite, LevelPos2);
	
	std::cout << initTimer.restart().asSeconds() << std::endl;

	//PumpMeter
	m_sprite_manager->LoadSprite("pumpbar.png", "PumpMeter", 0, 0, 500, 65, 1, 1);
	PumpTexture = m_sprite_manager->GetTextures()["PumpMeterTexture"];
	PumpSprite = m_sprite_manager->GetSprites()["PumpMeter"];
	PumpSprite.setTexture(PumpTexture);
	sf::Vector2f PumpPos = sf::Vector2f(100, 50);
	m_pumpMeter = new PumpMeter(PumpSprite, PumpPos);

	std::cout << initTimer.restart().asSeconds() << std::endl;

	//Player
	m_sprite_manager->LoadSprite("player_move.png", "Player", 0, 0, 2048, 256, 1, 1);
	PlayerTexture = m_sprite_manager->GetTextures()["PlayerTexture"];
	PlayerSprite = m_sprite_manager->GetSprites()["Player"];
	PlayerSprite.setTexture(PlayerTexture);
	sf::Vector2f playerPOS = sf::Vector2f(800.0f, 200.0f);
	m_player = new Player(PlayerSprite, playerPOS);
	
	std::cout << initTimer.restart().asSeconds() << std::endl;

	//Enemy
	m_sprite_manager->LoadSprite("AOE.png", "EnemyAoe", 0, 0, 1024, 128, 1, 1);
	EnemyAoeTexture = m_sprite_manager->GetTextures()["EnemyAoeTexture"];
	EnemyAoeSprite = m_sprite_manager->GetSprites()["EnemyAoe"];
	EnemyAoeSprite.setTexture(EnemyAoeTexture);
	sf::Vector2f enemyPOS = sf::Vector2f(400.0f, 50.0f);
	sf::Vector2f enemyPOS2 = sf::Vector2f(900.0f, 900.0f);
	m_objectContainer.push_back(new EnemyAOE(EnemyAoeSprite, enemyPOS));
	m_objectContainer.push_back(new EnemyAOE(EnemyAoeSprite, enemyPOS2));
	
	std::cout << initTimer.restart().asSeconds() << std::endl;

	//Attack
	m_sprite_manager->LoadSprite("image.png", "Attack", 0, 0, 96, 128, 1, 1);
	AttackTexture = m_sprite_manager->GetTextures()["AttackTexture"];
	AttackSprite = m_sprite_manager->GetSprites()["Attack"];
	AttackSprite.setTexture(AttackTexture);	

	std::cout << initTimer.restart().asSeconds() << std::endl;
				
	return true;
}

void Engine::Cleanup()
{
	m_player->Cleanup();
	m_enemy->Cleanup();
}

void Engine::Run()
{
	//Init a clock
	sf::Clock m_clock;

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

		//Attack Input
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
		{
			m_player->Attack();
		}
		//Movement Input
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
						
		//Update Player
		m_player->Update(m_angle, m_direction, m_elapsedTime);	
		//Player Attack
		if(m_player->GetAttacking() == true && m_attackContainer.size() < 1)
		{
			std::cout << "Attack!" << std::endl;			
			sf::Vector2f attackPOS = m_player->GetPosition();
			if(m_angle == 0) //up
				attackPOS += sf::Vector2f(0, -128);
			else if(m_angle == 45)//up right
				attackPOS += sf::Vector2f(120, -128);
			else if(m_angle == 90)//right
				attackPOS += sf::Vector2f(128, 0);
			else if(m_angle == 135)//down right
				attackPOS += sf::Vector2f(120, 128);
			else if(m_angle == 180)//down
				attackPOS += sf::Vector2f(0, 128);
			else if(m_angle == 225)//down left
				attackPOS += sf::Vector2f(-120, 128);
			else if(m_angle == 270)//left
				attackPOS += sf::Vector2f(-128, 0);
			else if(m_angle == 315)//up left
				attackPOS += sf::Vector2f(-120, -128);

			m_attackContainer.push_back( new PlayerAttack(AttackSprite ,attackPOS, m_player->GetWeaponSize() ) );
		}

		//std::cout << m_player->GetHP() << std::endl;

		if(!m_attackContainer.empty())
			{
				m_attackContainer[0]->Update(m_elapsedTime);
				if(m_attackContainer[0]->Dead())
				{
					m_attackContainer.pop_back();
				}
			}
		//Update Enemies
		if(!m_objectContainer.empty())
		{
			for(int object = 0; object < m_objectContainer.size(); object++)
			{
				m_objectContainer[object]->Update(m_elapsedTime);
				
				if(m_objectContainer[object]->GetHP() == 0)
				{
					delete m_objectContainer[object];
					m_objectContainer[object] = nullptr;
					m_objectContainer.erase(m_objectContainer.begin() + object);
					m_player->ChangeHP(20);
				}				
			}
		}

		//Update misc
		m_pumpMeter->Update(m_player->GetHP());
		m_level_top->Update(m_elapsedTime);
		m_level_bottom->Update(m_elapsedTime);

		//Collision
		m_collisionManager->Add(m_player);

		if(!m_objectContainer.empty())
		{
			for(int object = 0; object < m_objectContainer.size(); object++)
			{
				m_collisionManager->Add(m_objectContainer[object]);
			}
		}

		if(!m_attackContainer.empty())
		{
			m_collisionManager->Add(m_attackContainer[0]);
		}		
		m_collisionManager->CheckCollision();


		//Draw
		Draw();


		if(m_player->GetHP() >= 100 || m_player->GetHP() <= 0)
		{
			break;
		}						
	}
}

void Engine::Draw()
{

		m_window.clear(sf::Color(0x11, 0x11, 0x11, 0xff));
		//Level	
		m_window.draw(m_level_top->GetSprite());
		m_window.draw(m_level_bottom->GetSprite());

		//Player
		m_window.draw(m_player->GetSprite());
		//Enemies
		if(!m_objectContainer.empty())
		{
			for(int object = 0; object < m_objectContainer.size(); object++)
			{
				m_window.draw(m_objectContainer[object]->GetSprite());
			}
		}
		//attacks
		if(!m_attackContainer.empty())
		{
			m_window.draw(m_attackContainer[0]->GetSprite());
		}

		//Pump
		m_window.draw(m_pumpMeter->GetSprite());

		m_window.display();	

}