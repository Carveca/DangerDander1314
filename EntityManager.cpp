//Entity Manager source file

#include "stdafx.h"
#include "EntityManager.h"

#include "CollisionManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "EnemyAOE.h"


EntityManager::EntityManager(sf::Sprite* playerSprite, sf::Vector2f playerlPOS, sf::Sprite* playerAttackSprite, sf::Sprite* powSprite)
{
	m_collisionManager = new CollisionManager;

	m_powSprite = powSprite;
	m_player = new Player(playerSprite, playerlPOS, playerAttackSprite);	
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
	UpdateEnemyAOE(deltatime);

	CollisionCheck();
}

void EntityManager::Draw(sf::RenderWindow* window)
{
	DrawEnemyAOE(window);

	DrawPlayer(window);
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
		}
	}

	m_collisionManager->CheckCollision();
}


void EntityManager::CheckHP()
{

}

//Add

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
			if(!m_playerAttack[0]->GetHit())
			{
				m_playerAttack[0]->GetSprite();
			}
		}
	}
	else
	{
		m_player->SetAttackAnimationStop();

		window->draw(*m_player->GetSprite());
	}
}

//EnemyAOE - Update and Draw

void EntityManager::UpdateEnemyAOE(float &deltatime)
{
	if( !m_enemyAOE.empty() )
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			m_enemyAOE[i]->Update(deltatime);

			if(m_enemyAOE[i]->GetHP() <= 0)
			{
				delete m_enemyAOE[i];
				m_enemyAOE[i] = nullptr;
				m_enemyAOE.erase(m_enemyAOE.begin() + i);
				m_player->ChangeHP(20);
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