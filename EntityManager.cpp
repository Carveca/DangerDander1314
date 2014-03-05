//Entity Manager source file

#include "stdafx.h"
#include "EntityManager.h"

#include "CollisionManager.h"
#include "MusicManager.h"
#include "SoundManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "PumpMeter.h"

#include "EnemyAOE.h"


EntityManager::EntityManager(sf::Sprite* playerSprite, sf::Vector2f playerlPOS, sf::Sprite* playerAttackSprite, sf::Sprite* playerdeathsprite, sf::Sprite* powSprite, SoundManager* soundmanager, MusicManager* musicmanager)
{
	m_collisionManager = new CollisionManager;

	m_soundManager = soundmanager;
	m_soundManager->LoadSound("sfx_pumpmeter_increase_1.wav", "PumpIncrease");

	m_musicManager = musicmanager;
	
	m_powSprite = powSprite;
	m_player = new Player(playerSprite, playerlPOS, playerAttackSprite, soundmanager, playerdeathsprite);

	m_musicNR = 0;
	m_musicSwitch = false;

}

EntityManager::~EntityManager()
{
	if(m_collisionManager != nullptr)
	{
		delete m_collisionManager;
		m_collisionManager = nullptr;
	}

	if(m_player != nullptr)
	{
		delete m_player;
		m_player = nullptr;
	}

	m_enemyAOE.clear();
}

//Loop Methods

void EntityManager::Update(float &angle, sf::Vector2f &direction,float &deltatime)
{
	UpdatePlayer(angle, direction, deltatime);

	UpdatePumpMeter(m_player->GetHP());

	UpdateEnemyAOE(deltatime);
	
	CollisionCheck();	
}

void EntityManager::Draw(sf::RenderWindow* window)
{
	DrawEnemyAOE(window);
		
	DrawPlayer(window);

	DrawPumpMeter(window);

}

void EntityManager::CollisionCheck()
{
	m_collisionManager->Add(m_player);

	if(!m_playerAttack.empty())
	{
		m_collisionManager->Add(m_playerAttack[0]);
	}

	if(!m_enemyAOE.empty())
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			m_collisionManager->Add(m_enemyAOE[i]);
			m_collisionManager->Add(m_enemyAOE[i]->GetAttack());
		}
	}

	m_collisionManager->CheckCollision();
}


void EntityManager::CheckHP()
{

}

void EntityManager::MusicSwitch()
{
	//music switch
	m_musicSwitch = false;
	m_musicNRprevious = m_musicNR;

	if(m_player->GetHP() >= 80)
	{
		m_musicNR = 3;
		//m_musicManager->LoadMusic("soundtrack_high_1.wav");
		//m_musicManager->Play();
	}
	else if(m_player->GetHP() <= 20)
	{
		m_musicNR = 2;
		//m_musicManager->LoadMusic("soundtrack_low_1.wav");
		//m_musicManager->Play();
	}
	else
	{
		m_musicNR = 1;
		//m_musicManager->LoadMusic("soundtrack_mid_1.wav");
		//m_musicManager->Play();
	}

	if(m_musicNR != m_musicNRprevious)
		m_musicSwitch = true;


	//Music play

	if(m_musicSwitch)
	{
		m_musicManager->Offset();		

		if(m_musicNR == 3)
		{
			m_musicManager->LoadMusic("soundtrack_high_1.wav");
			m_musicManager->PlayWithOffset();
		}
		else if(m_musicNR == 2)
		{
			m_musicManager->LoadMusic("soundtrack_low_1.wav");
			m_musicManager->PlayWithOffset();
		}
		else
		{
			m_musicManager->LoadMusic("soundtrack_mid_1.wav");
			m_musicManager->PlayWithOffset();
		}

	}
}

//Add

void EntityManager::AddSounds(SoundManager* soundmanager)
{
	m_soundManager = soundmanager;
}

void EntityManager::AddMusic(MusicManager* musicmanager)
{
	m_musicManager = musicmanager;
}

void EntityManager::AddPumpMeter(sf::Sprite* pumpSprite, sf::Sprite* indicatorSprite, sf::Sprite* indicatorEffectSprite, sf::Sprite* leftWarningSprite, sf::Sprite* rightWarningSprite, sf::Vector2f &pumpMeterPOS)
{
	m_pumpMeter = new PumpMeter(pumpSprite, indicatorSprite, indicatorEffectSprite, leftWarningSprite, rightWarningSprite, pumpMeterPOS);
}

void EntityManager::AddEnemyAOE(EnemyAOE* enemyAOE)
{
	m_enemyAOE.push_back(enemyAOE);
}

//Player - Update and Draw

void EntityManager::UpdatePlayer(float &angle, sf::Vector2f &direction, float &deltatime)
{
	m_player->Update(angle, direction, deltatime);

	//Player Attack
	if(m_player->GetAttacking() == true && m_playerAttack.size() < 1)
	{		
		sf::Vector2f attackPOS = m_player->GetPosition();
		if(angle == 0) //up
			attackPOS += sf::Vector2f(0, -128);
		else if(angle == 45)//up right
			attackPOS += sf::Vector2f(120, -120);
		else if(angle == 90)//right
			attackPOS += sf::Vector2f(128, 0);
		else if(angle == 135)//down right
			attackPOS += sf::Vector2f(120, 120);
		else if(angle == 180)//down
			attackPOS += sf::Vector2f(0, 128);
		else if(angle == 225)//down left
			attackPOS += sf::Vector2f(-120, 120);
		else if(angle == 270)//left
			attackPOS += sf::Vector2f(-128, 0);
		else if(angle == 315)//up left
			attackPOS += sf::Vector2f(-120, -120);

		m_playerAttack.push_back( new PlayerAttack(m_powSprite, attackPOS, m_player->GetWeaponSize()) );
	}

	if(!m_playerAttack.empty())
	{
		m_playerAttack[0]->Update(deltatime);
		if(m_playerAttack[0]->Dead())
		{
			m_playerAttack.pop_back();
					
		}
	}
	 
}

void EntityManager::DrawPlayer(sf::RenderWindow* window)
{
	if(m_player->GetAttackTimer() <= 0.3 && m_player->GetAttackTimer() > 0.0)
	{
		window->draw(*m_player->GetAttackSprite());

		if(!m_playerAttack.empty())
		{
			for( unsigned int i = 0; i < m_playerAttack.size(); i++)
			{
				if(m_playerAttack[0]->GetHit())
				{
					m_powSprite->setPosition(m_playerAttack[0]->GetPosition());
					window->draw(*m_powSprite);
				}
			}
		}
	}
	else
	{
		m_player->SetAttackAnimationStop();

		window->draw(*m_player->GetSprite());
	}
}

//PumpMeter - Update and Draw

void EntityManager::UpdatePumpMeter(int hpvalue)
{
	m_pumpMeter->Update(hpvalue);
}

void EntityManager::DrawPumpMeter(sf::RenderWindow* window)
{
	window->draw(*m_pumpMeter->m_leftWarningSprite);
	window->draw(*m_pumpMeter->m_rightWarningSprite);
	
	window->draw(*m_pumpMeter->GetSprite());

	window->draw(*m_pumpMeter->m_indicatorEffectSprite);
	window->draw(*m_pumpMeter->m_indicatorSprite);
}


//EnemyAOE - Update and Draw

void EntityManager::UpdateEnemyAOE(float &deltatime)
{
	if( !m_enemyAOE.empty() )
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			m_enemyAOE[i]->Update(deltatime);

			if(m_enemyAOE[i]->GetPosition().y >= 1100)
			{
				delete m_enemyAOE[i];
				m_enemyAOE[i] = nullptr;
				m_enemyAOE.erase(m_enemyAOE.begin() + i);
			}
			else if(m_enemyAOE[i]->GetHP() <= 0)
			{
				delete m_enemyAOE[i];
				m_enemyAOE[i] = nullptr;
				m_enemyAOE.erase(m_enemyAOE.begin() + i);
				m_player->ChangeHP(20);
				m_soundManager->PlaySound("PumpIncrease");
			}
		}
	}
}

void EntityManager::DrawEnemyAOE(sf::RenderWindow* window)
{
	if( !m_enemyAOE.empty() )
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			window->draw(*m_enemyAOE[i]->GetAttack()->GetSprite());
			window->draw(*m_enemyAOE[i]->GetSprite());
		}
	}
}