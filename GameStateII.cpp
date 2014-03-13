//GameState II source file

#include "stdafx.h"
#include "GameStateII.h"

#include "EntityManager.h"
#include "SpriteManager.h"
#include "MusicManager.h"
#include "CollisionManager.h"

#include "SoundManager.h"

#include "SpawnerBullet.h"
#include "SpawnerEnemyRanged.h"
#include "SpawnerEnemyMelee.h"
#include "SpawnerAOEenemy.h"
#include "SpawnerRubbishBin.h"
#include "SpawnerRubbishAndPower.h"


#include "Player.h"
#include "RubbishBin.h"
#include "EnemyRanged.h"
#include "EnemyMelee.h"
#include "MeleeAttack.h"
#include "Level.h"

GameStateII::GameStateII()
{
	m_done = false;
	m_paused = false;
}

bool GameStateII::Enter(SpriteManager* spritemanager, MusicManager* musicmanager)
{
	m_done = false;
	m_loading = true;
	m_loadingDone = false;

	m_direction.x = 0;
	m_direction.y = 0;
	m_angle = 0;

	//Managers
	m_spriteManager = spritemanager;
	m_loadDone = m_spriteManager->GetSprite("loading_done.png", 1920, 1080);


	m_musicManager = musicmanager;

	m_musicManager->LoadMusic("soundtrack_long.wav");
	m_musicManager->Play();

	//pause screen
	m_pauseScreen = m_spriteManager->GetSprite("pause_menu.png", 1920, 1080);

	//new manager and spawners
	m_soundManager = new SoundManager;
	m_soundManager->Initialize("../Sounds/");
	
	m_entityManager = new EntityManager(m_spriteManager, m_spriteManager->GetSprite("player_weapon.png", 2048, 256), sf::Vector2f(950, 540), m_spriteManager->GetSprite("player_attack.png", 1024, 256), m_spriteManager->GetSprite("player_death.png", 256, 256) , m_spriteManager->GetSprite("pow_effect.png", 128, 128), m_soundManager, m_musicManager);
	//m_entityManager->AddPumpMeter(m_spriteManager->GetSprite("new_pumpmeter.png", 800, 246), m_spriteManager->GetSprite("pumpmeter_indicator.png", 70, 94), m_spriteManager->GetSprite("indicator_effect.png", 150, 150), m_spriteManager->GetSprite("meter_effect_left.png", 800, 246), m_spriteManager->GetSprite("meter_effect_right.png", 800, 246), sf::Vector2f(0, 0));
	
	//Spawners
	
	m_spawnerEnemyMelee = new SpawnerEnemyMelee( m_spriteManager->GetSprite("melee_enemy_move.png", 2048, 128), m_spriteManager->GetSprite("melee_enemy_attack.png", 1024, 128), m_spriteManager->GetSprite("melee_enemy_death.png", 512, 128), sf::Vector2f(1200, -100), m_soundManager);
	m_spawnerBullet = new SpawnerBullet(m_spriteManager->GetSprite("bullet.png", 16, 16), m_soundManager);
	m_spawnerEnemyRanged = new SpawnerEnemyRanged(m_spriteManager->GetSprite("ranged_enemy_move.png", 2048, 128), m_spriteManager->GetSprite("ranged_enemy_attack.png", 1024, 128), m_spriteManager->GetSprite("ranged_enemy_death.png", 512, 128), sf::Vector2f(600, -200), m_soundManager);
	m_spawnerAOEenemy = new SpawnerAOEenemy(m_spriteManager->GetSprite("AOE.png", 2056, 256), m_spriteManager->GetSprite("aoe_attack.png", 256, 256), sf::Vector2f(400, -100), m_soundManager );
	
	m_spawnerRubbishBin = new SpawnerRubbishBin(m_spriteManager->GetSprite("rubbish_bin.png", 128, 128), m_spriteManager->GetSprite("rubbish_bin_death.png", 1024, 128), sf::Vector2f(500, -100), m_soundManager);
	m_spawnerRubbishBin2 = new SpawnerRubbishBin(m_spriteManager->GetSprite("rubbish_bin.png", 128, 128), m_spriteManager->GetSprite("rubbish_bin_death.png", 1024, 128), sf::Vector2f(1400, -100), m_soundManager);
	
	m_spawnerRubbishAndPower = new SpawnerRubbishAndPower(m_spriteManager->GetSprite("blue_cow.png", 256, 64), m_spriteManager->GetSprite("happy_pill.png", 256, 64), m_spriteManager->GetSprite("trash.png", 903, 128), m_soundManager);
	
	//Level
	m_levelTop = new Level( m_spriteManager->GetSprite("new_gamespace.png", 1920, 1080), sf::Vector2f(0, 0));
	m_levelBottom = new Level( m_spriteManager->GetSprite("new_gamespace.png", 1920, 1080), sf::Vector2f(0, -1079) );

	return true;
}

void GameStateII::Exit()
{
	if(m_soundManager != nullptr)
	{
		delete m_soundManager;
		m_soundManager = nullptr;
	}

	if(m_entityManager != nullptr)
	{
		delete m_entityManager;
		m_entityManager = nullptr;
	}

	if(m_spawnerBullet != nullptr)
	{
		delete m_spawnerBullet;
		m_spawnerBullet = nullptr;
	}

	if(m_spawnerEnemyRanged != nullptr)
	{
		delete m_spawnerEnemyRanged;
		m_spawnerEnemyRanged = nullptr;
	}

	if(m_spawnerRubbishBin != nullptr)
	{
		delete m_spawnerRubbishBin;
		m_spawnerRubbishBin = nullptr;
	}

	if(m_spawnerAOEenemy != nullptr)
	{
		delete m_spawnerAOEenemy;
		m_spawnerAOEenemy = nullptr;
	}

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

}

//State loop

bool GameStateII::Update(float &deltatime)
{
	//std::cout << "GameStateII" << std::endl;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		m_loading = false;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_nextState = "MenuStateII";
		m_done = true;
	}
	//Pause Screen
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
	{
		m_paused = true;
	}

	if(!m_loading)
	{
		if(m_paused)
		{
			GamePause();
		}
		else if(!m_paused)
		{
			RealTime(deltatime);
		}
	}

	/*
	Input();
	//Spawner Update
	m_spawnerAOEenemy->Update(deltatime);
	if(m_spawnerAOEenemy->GetSpawnState())
	{
		m_entityManager->AddEnemyAOE( m_spawnerAOEenemy->Spawn() );
	}
	m_spawnerRubbishBin->Update(deltatime);
	if(m_spawnerRubbishBin->GetSpawnState())
	{
		m_entityManager->AddRubbishBin( m_spawnerRubbishBin->Spawn() );
	}
	
	m_entityManager->Update(m_angle, m_direction, deltatime);	

	m_levelTop->Update(deltatime);
	m_levelBottom->Update(deltatime);

	if(m_entityManager->m_player->GetHP() == 100 || m_entityManager->m_player->GetHP() == 0)
	{
		GameOver();
	}
	*/

	return m_done;
}

void GameStateII::Draw(sf::RenderWindow* window)
{

}

void GameStateII::Draw(sf::RenderWindow* window, float &deltatime)
{
	if(m_loading)
	{
		window->draw(*m_loadDone);
	}

	else if(!m_loading);
	{
		if(m_paused)
		{
			window->draw(*m_pauseScreen);
		}
		else if(!m_paused && !m_loading)
		{
			window->draw(*m_levelTop->GetSprite());
			window->draw(*m_levelBottom->GetSprite());

			m_entityManager->Draw(window, deltatime, m_angle);
		}
	}

}

//state switch

std::string GameStateII::Next()
{
	return m_nextState;
}

bool GameStateII::IsType(const std::string &type)
{
	return type.compare("GameStateII") == 0;
}

//private

void GameStateII::Input()
{
	//Attack Input
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
	{
		m_entityManager->m_player->Attack();
	}
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num1 ) )
	{
		m_entityManager->m_player->UseHappyPill();
	}
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num2 ) )
	{
		m_entityManager->m_player->UseBlueCow();
	}
	
	//Movement Input
	m_direction.x = 0;
	m_direction.y = 0;	

	//m_angle = 0;

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

void GameStateII::GameOver()
{
	if(m_entityManager->m_player->GetHP() == 100)
	{
		m_nextState = "GameOverHeart";
		m_done = true;
	}
	else if(m_entityManager->m_player->GetHP() == 0)
	{
		m_nextState = "GameOverSleep";
		m_done = true;
	}
}

void GameStateII::GamePause()
{
	
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::Q) )
	{
		m_nextState = "quit";
		m_done = true;
		m_paused = false;
	}
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::M) )
	{
		m_nextState = "MenuStateII";
		//m_done = true;
		m_paused = false;
	}
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::G) )
		m_paused = false;
	
}

void GameStateII::RealTime(float &deltatime)
{
	Input();

	//Spawn Melee Attack
	if(!m_entityManager->m_enemyMelee.empty())
	{
		for( unsigned int i = 0; i < m_entityManager->m_enemyMelee.size(); i++)
		{
			if(m_entityManager->m_enemyMelee[i]->GetAttacking() )
			{
				m_entityManager->AddMeleeAttack( new MeleeAttack(m_spriteManager->GetSprite("pow_effect.png", 128, 128), m_entityManager->m_player->GetPosition()) );
			}
		}
	}
	//Spawner Enemy Melee
	m_spawnerEnemyMelee->Update(deltatime);
	if(m_spawnerEnemyMelee->GetSpawnState())
	{
		m_entityManager->AddEnemyMelee( m_spawnerEnemyMelee->Spawn() );
	}
	//Spawner Enemy Ranged
	m_spawnerEnemyRanged->Update(deltatime);
	if(m_spawnerEnemyRanged->GetSpawnState())
	{
		m_entityManager->AddEnemyRanged( m_spawnerEnemyRanged->Spawn() );
	}
	//Spawn Bullet
	if(!m_entityManager->m_enemyRanged.empty())
	{
		for(unsigned int i = 0; i < m_entityManager->m_enemyRanged.size(); i++)
		{
			if( m_entityManager->m_enemyRanged[i]->GetAttacking() )
			{
				m_entityManager->AddBullet(m_spawnerBullet->Spawn(m_entityManager->m_enemyRanged[i]->GetPosition(), m_entityManager->m_enemyRanged[i]->GetDirection()) );
			}
		}
	}

	//Spawner AOE
	m_spawnerAOEenemy->Update(deltatime);
	if(m_spawnerAOEenemy->GetSpawnState())
	{
		m_entityManager->AddEnemyAOE( m_spawnerAOEenemy->Spawn() );
	}
	//Spawner Rubbish Bin
	m_spawnerRubbishBin->Update(deltatime);
	if(m_spawnerRubbishBin->GetSpawnState())
	{
		m_entityManager->AddRubbishBin( m_spawnerRubbishBin->Spawn() );
	}
	m_spawnerRubbishBin2->Update(deltatime);
	if(m_spawnerRubbishBin2->GetSpawnState())
	{
		m_entityManager->AddRubbishBin( m_spawnerRubbishBin2->Spawn() );
	}
	//Spawner Rubbish and Power
	m_spawnerRubbishAndPower->Update();
	if(!m_entityManager->m_rubbishBin.empty())
	{
		for(unsigned int i = 0; i < m_entityManager->m_rubbishBin.size(); i++)
		{
			if(m_entityManager->m_rubbishBin[i]->m_knockedOver)
			{
				if(!m_entityManager->m_rubbishBin[i]->m_spawnedTrash)
				{
					m_spawnerRubbishAndPower->SetSpawnPOS(m_entityManager->m_rubbishBin[i]->RubbishSpawn(m_angle));

					int drop = rand() % 100;

					if(drop >= 20)
					{
						m_entityManager->AddRubbishpile(m_spawnerRubbishAndPower->SpawnRubbish(m_angle));
					}
					else if (drop < 20)
					{
						int powerup = rand() % 100;

							if(powerup > 50)
							{
								m_entityManager->AddBlueCow(m_spawnerRubbishAndPower->SpawnBlueCow());
							}
							else if(powerup <= 50)
							{
								m_entityManager->AddHappyPill(m_spawnerRubbishAndPower->SpawnHappyPill());
							}
					}
					m_entityManager->m_rubbishBin[i]->m_spawnedTrash = true;
				}
			}
		}
	}
	
	m_entityManager->Update(m_angle, m_direction, deltatime);	

	m_levelTop->Update(deltatime);
	m_levelBottom->Update(deltatime);

	if(m_entityManager->m_player->GetHP() == 100 || m_entityManager->m_player->GetHP() == 0)
	{
		GameOver();
	}
}