//Engine source file

#include "stdafx.h"
#include "Engine.h"

#include "SpriteManager.h"
#include "Player.h"
#include "EnemyMelee.h"
#include "Collider.h"

#include <iostream>

Engine::Engine()
{
	m_direction.x = 0.0f;
	m_direction.y = 0.0f;


}

Engine::~Engine()
{

}

bool Engine::Initialize()
{
	m_window.create(sf::VideoMode(1920, 1080), "Dangerous Dander");
		
	m_sprite_manager = new SpriteManager;
	m_sprite_manager->Initialize("../Sprites/");
	m_sprite_manager->LoadSprite("AOE.png", "Player", 0, 0, 128, 128, 2, 2);

	PlayerTexture = m_sprite_manager->m_textures["PlayerTexture"];
	PlayerSprite = m_sprite_manager->m_sprites["Player"];
	PlayerSprite.setTexture(PlayerTexture);
	
	m_player = new Player(PlayerSprite);
	sf::Vector2f playerPOS;	playerPOS.x = 100.0f; playerPOS.y = 100.0f;
	m_player->SetPosition(playerPOS);
		
	return true;
}

void Engine::Cleanup()
{

}

void Engine::Run()
{
	while(m_window.isOpen())
	{		
		m_elapsed_time = m_clock.restart().asSeconds();	
					
		sf::Event event;
			
		while(m_window.pollEvent(event))
		{				
			if(event.type == sf::Event::Closed)
			{
				m_window.close();
			}
						
		}
		//Movement
			m_direction.x = 0.0f;
			m_direction.y = 0.0f;			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_direction.x = -1;
				m_direction.y = -1;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_direction.x = 1;
				m_direction.y = -1;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_direction.y = -1;
			}		
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_direction.x = -1;
				m_direction.y = 1;
			}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_direction.x = 1;
				m_direction.y = 1;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_direction.y = 1;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_direction.x = -1;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_direction.x = 1;
			}
		m_player->Move(m_direction, m_elapsed_time);

		m_player->Update();

		std::cout << "X: " << m_player->GetPosition().x << "Y: " << m_player->GetPosition().y << std::endl;
		std::cout << "X: " << m_player->GetSprite().getPosition().x << "Y: " << m_player->GetSprite().getPosition().y << std::endl;

		m_window.clear(sf::Color(0x11, 0x22, 0x33, 0xff));
		m_window.draw(m_player->GetSprite());
		m_window.display();		
	}
}

/*
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Up && event.key.code == sf::Keyboard::Left)
				{
					m_direction.x = -1.0f;
					m_direction.y = -1.0f;
				}

				else if(event.key.code == sf::Keyboard::Up && event.key.code == sf::Keyboard::Right)
				{
					m_direction.x = 1.0f;
					m_direction.y = -1.0f;
				}

				else if(event.key.code == sf::Keyboard::Up)
				{
					m_direction.y = -1.0f;
				}

				else if(event.key.code == sf::Keyboard::Down && event.key.code == sf::Keyboard::Left)
				{
					m_direction.x = -1.0f;
					m_direction.y = 1.0f;
				}

				else if(event.key.code == sf::Keyboard::Down && event.key.code == sf::Keyboard::Right)
				{
					m_direction.x = 1.0f;
					m_direction.y = 1.0f;
				}

				else if(event.key.code == sf::Keyboard::Down)
				{
					m_direction.y = 1.0f;
				}

				else if(event.key.code == sf::Keyboard::Left)
				{
					m_direction.x = -1.0f;
				}

				else if(event.key.code == sf::Keyboard::Right)
				{
					m_direction.x = 1.0f;
				}
				
			}
			*/