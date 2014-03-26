//Entity Manager source file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EntityManager.h"

#include "CollisionManager.h"
#include "MusicManager.h"
#include "SoundManager.h"
#include "SpriteManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "HUD.h"

#include "MeleeAttack.h"
#include "EnemyMelee.h"
#include "Bullet.h"
#include "EnemyRanged.h"
#include "EnemyRanged2.h"
#include "EnemyAOE.h"
#include "RubbishBin.h"
#include "Rubbishpile.h"
#include "HappyPill.h"
#include "BlueCow.h"


EntityManager::EntityManager(SpriteManager* spritemanager ,sf::Sprite* playerSprite, sf::Vector2f playerlPOS, sf::Sprite* playerAttackSprite, sf::Sprite* playerdeathsprite, sf::Sprite* powSprite, SoundManager* soundmanager, MusicManager* musicmanager)
{
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_collisionManager = new CollisionManager;

	m_soundManager = soundmanager;
	m_soundManager->LoadSound("pumpmeter_increase.wav", "PumpIncrease");
	m_soundManager->LoadSound("main_attack_pow.wav", "Pow");

	m_musicManager = musicmanager;
	m_spriteManager = spritemanager;

	m_powSprite = powSprite;
	m_player = new Player(playerSprite, playerlPOS, playerAttackSprite, soundmanager, playerdeathsprite, m_spriteManager->GetSprite("blue_cow_effect.png", 2048, 256), m_spriteManager->GetSprite("happy_effect.png", 2048, 256) );

	m_HUD = new HUD(m_spriteManager);

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
	CollisionCheck();

	UpdatePlayer(angle, direction, deltatime);

	UpdateHUD(m_player, deltatime);

	//UpdatePumpMeter(m_player->GetHP());
	
	//enemies

	UpdateMeleeAttack(deltatime);

	UpdateEnemyMelee(deltatime);

	UpdateEnemyAOE(deltatime);

	UpdateEnemyRanged(deltatime);

	UpdateEnemyRanged2(deltatime);

	UpdateBullet(deltatime);

	UpdateRubbishBin(deltatime);

	UpdateRubbishPile(deltatime);

	//power ups

	UpdateBlueCow(deltatime);

	UpdateHappyPill(deltatime);
	
	//CollisionCheck();	

	CheckHP(deltatime, angle);
}

void EntityManager::Draw(sf::RenderWindow* window, float &deltatime, float &playerangle )
{
	DrawRubbishBin(window, deltatime, playerangle);

	DrawRubbishPile(window);

	DrawEnemyMelee(window);

	DrawEnemyranged(window);

	DrawEnemyranged2(window);

	DrawBlueCow(window);

	DrawHappyPill(window);

	DrawEnemyAOE(window);
		
	DrawPlayer(window);

	DrawMeleeAttack(window);

	DrawBullet(window);

	DrawHud(window);

}

void EntityManager::CollisionCheck()
{
	m_collisionManager->Add(m_player);

	if(!m_playerAttack.empty())
	{
		m_collisionManager->Add(m_playerAttack[0]);
	}

	if( !m_meleeAttacks.empty() )
	{
		for(unsigned int i = 0; i < m_meleeAttacks.size(); i++)
		{
			m_collisionManager->Add(m_meleeAttacks[i]);
		}
	}

	if( !m_enemyMelee.empty() )
	{
		for(unsigned int i = 0; i < m_enemyMelee.size(); i++)
		{
			if(!m_enemyMelee[i]->isDead())
			m_collisionManager->Add(m_enemyMelee[i]);
		}
	}

	if( !m_bullets.empty() )
	{
		for(unsigned int i = 0; i < m_bullets.size(); i++)
		{
			m_collisionManager->Add(m_bullets[i]);
		}
	}

	if(!m_enemyRanged.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged.size(); i++)
		{
			if(!m_enemyRanged[i]->isDead())
			m_collisionManager->Add(m_enemyRanged[i]);
		}
	}

	if(!m_enemyRanged2.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged2.size(); i++)
		{
			if(!m_enemyRanged2[i]->isDead())
			m_collisionManager->Add(m_enemyRanged2[i]);
		}
	}

	if(!m_enemyAOE.empty())
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			if(!m_enemyAOE[i]->isDead())
			{
				m_collisionManager->Add(m_enemyAOE[i]);
				m_collisionManager->Add(m_enemyAOE[i]->GetAttack());
			}
		}
	}

	if(!m_rubbishBin.empty())
	{
		for(unsigned int i = 0; i < m_rubbishBin.size(); i++)
		{
			m_collisionManager->Add(m_rubbishBin[i]);
		}
	}

	if(!m_blueCow.empty())
	{
		for(unsigned int i = 0; i < m_blueCow.size(); i++)
		{
			m_collisionManager->Add(m_blueCow[i]);
		}
	}

	if(!m_happyPill.empty())
	{
		for(unsigned int i = 0; i < m_happyPill.size(); i++)
		{
			m_collisionManager->Add(m_happyPill[i]);
		}
	}

	m_collisionManager->CheckCollision();
}

//m_player->ChangeHP(20);
//m_soundManager->PlaySound("PumpIncrease");

void EntityManager::CheckHP(float &deltatime, float &angle)
{
	if(!m_playerAttack.empty())
	{
		if(m_playerAttack[0]->isDead())
		{
			m_playerAttack.pop_back();					
		}
	}

	if(!m_happyPill.empty())
	{
		for(unsigned int i = 0; i < m_happyPill.size(); i++)
		{
			if(m_happyPill[i]->GetHP() <= 0 || m_happyPill[i]->GetPosition().y >= 1100)
			{
				delete m_happyPill[i];
				m_happyPill[i] = nullptr;
				m_happyPill.erase(m_happyPill.begin() + i);
			}
		}
	}

	if(!m_blueCow.empty())
	{
		for(unsigned int i = 0; i < m_blueCow.size(); i++)
		{
			if(m_blueCow[i]->GetHP() <= 0 || m_blueCow[i]->GetPosition().y >= 1100)
			{
				delete m_blueCow[i];
				m_blueCow[i] = nullptr;
				m_blueCow.erase(m_blueCow.begin() + i);
			}
		}
	}

	if( !m_meleeAttacks.empty() )
	{
		for(unsigned int i = 0; i < m_meleeAttacks.size(); i++)
		{
			if( m_meleeAttacks[i]->GetHP() <= 0 )
			{
				delete m_meleeAttacks[i];
				m_meleeAttacks[i] = nullptr;
				m_meleeAttacks.erase( m_meleeAttacks.begin() + i );
				m_player->ChangeHP(m_reader->m_settings["MeleeDMG"]);
				//m_soundManager->PlaySound("PumpIncrease");
			}
		}
	}

	if( !m_enemyMelee.empty() )
	{
		for(unsigned int i = 0; i < m_enemyMelee.size(); i++)
		{
			if(m_enemyMelee[i]->GetPosition().y >= 1100 || m_enemyMelee[i]->GetDeathTimer() <= 0.0)
			{
				delete m_enemyMelee[i];
				m_enemyMelee[i] = nullptr;
				m_enemyMelee.erase(m_enemyMelee.begin() + i);
			}

			else if( m_enemyMelee[i]->GetHP() <= 0 && !m_enemyMelee[i]->isDead())
			{
				m_enemyMelee[i]->Dead();
				m_player->AddScore(m_enemyMelee[i]->GetPoints());
				//delete m_enemyMelee[i];
				//m_enemyMelee[i] = nullptr;
				//m_enemyMelee.erase( m_enemyMelee.begin() + i );
				m_player->ChangeHP(5);
				m_soundManager->PlaySound("Pow");
				
			}
		}
	}

	if(!m_bullets.empty())
	{
		for(unsigned int i = 0; i < m_bullets.size(); i++)
		{
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(m_bullets[i]->GetHP() <= 0)
			{
				delete m_bullets[i];
				m_bullets[i] = nullptr;
				m_bullets.erase(m_bullets.begin() + i);
				m_player->ChangeHP(m_reader->m_settings["BulletDMG"]);
				//m_soundManager->PlaySound("PumpIncrease");
			}
		}
	}

	if(!m_enemyRanged.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged.size(); i++)
		{
			if(m_enemyRanged[i]->GetPosition().y >= 1100 || m_enemyRanged[i]->GetDeathTimer() <= 0.0)
			{
				delete m_enemyRanged[i];
				m_enemyRanged[i] = nullptr;
				m_enemyRanged.erase(m_enemyRanged.begin() + i);
			}


			else if(m_enemyRanged[i]->GetHP() <= 0 && !m_enemyRanged[i]->isDead())
			{
				m_enemyRanged[i]->Dead();
				m_player->AddScore(m_enemyRanged[i]->GetPoints());
				//delete m_enemyRanged[i];
				//m_enemyRanged[i] = nullptr;
				//m_enemyRanged.erase(m_enemyRanged.begin() + i);
				m_player->ChangeHP(10);
				m_soundManager->PlaySound("Pow");
			}
		}
	}

	if(!m_enemyRanged2.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged2.size(); i++)
		{
			if(m_enemyRanged2[i]->GetPosition().y >= 1100 || m_enemyRanged2[i]->GetDeathTimer() <= 0.0)
			{
				delete m_enemyRanged2[i];
				m_enemyRanged2[i] = nullptr;
				m_enemyRanged2.erase(m_enemyRanged2.begin() + i);
			}


			else if(m_enemyRanged2[i]->GetHP() <= 0 && !m_enemyRanged2[i]->isDead())
			{
				m_enemyRanged2[i]->Dead();
			
				m_player->AddScore(m_enemyRanged2[i]->GetPoints());
				//delete m_enemyRanged2[i];
				//m_enemyRanged2[i] = nullptr;
				//m_enemyRanged2.erase(m_enemyRanged2.begin() + i);
				m_player->ChangeHP(10);
				m_soundManager->PlaySound("Pow");
			}
		}
	}

	if(!m_enemyAOE.empty())
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			if(m_enemyAOE[i]->GetPosition().y >= 1100 || m_enemyAOE[i]->GetDeathTimer() <= 0.0)
			{
				delete m_enemyAOE[i];
				m_enemyAOE[i] = nullptr;
				m_enemyAOE.erase(m_enemyAOE.begin() + i);
			}
			
			else if(m_enemyAOE[i]->GetHP() <= 0 && !m_enemyAOE[i]->isDead())
			{
				m_enemyAOE[i]->Dead();
				m_player->AddScore(m_enemyAOE[i]->GetPoints());
				m_player->ChangeHP(10);
				m_soundManager->PlaySound("Pow");
			}
		}
	}

	if(!m_rubbishBin.empty())
	{
		for(unsigned int i = 0; i < m_rubbishBin.size(); i++)
		{
			if(m_rubbishBin[i]->GetHP() <= 0)
			{
				m_rubbishBin[i]->m_dead = true;
				m_rubbishBin[i]->DeathAnimation(deltatime, angle);
			}
			if(m_rubbishBin[i]->GetPosition().y >= 1100)
			{
				delete m_rubbishBin[i];
				m_rubbishBin[i] = nullptr;
				m_rubbishBin.erase(m_rubbishBin.begin() + i);
			}
		}
	}
}

//Add

void EntityManager::AddEnemyAOE(EnemyAOE* enemyAOE)
{
	if(m_enemyAOE.size() < m_reader->m_settings["AOEEnemyNR"])
	{
		m_enemyAOE.push_back(enemyAOE);
	}

}

void EntityManager::AddMeleeAttack(MeleeAttack* meleeattack)
{
	m_meleeAttacks.push_back(meleeattack);
}

void EntityManager::AddEnemyMelee(EnemyMelee* enemymelee)
{
	if(m_enemyMelee.size() < m_reader->m_settings["MeleeEnemyNR"])
	{
		m_enemyMelee.push_back(enemymelee);
	}
}

void EntityManager::AddBullet(Bullet* bullet)
{
	m_bullets.push_back(bullet);
}

void EntityManager::AddEnemyRanged(EnemyRanged* enemyranged)
{
	if(m_enemyRanged.size() < m_reader->m_settings["RangedEnemyNR"])
	{
		m_enemyRanged.push_back(enemyranged);
	}
}

void EntityManager::AddEnemyRanged2(EnemyRanged2* enemyranged)
{
	if(m_enemyRanged2.size() < m_reader->m_settings["Ranged2EnemyNR"])
	{
		m_enemyRanged2.push_back(enemyranged);
	}
}

void EntityManager::AddRubbishBin(RubbishBin* rubbishbin)
{
	m_rubbishBin.push_back(rubbishbin);
}

void EntityManager::AddRubbishpile(Rubbishpile* rubbishpile)
{
	m_rubbishpile.push_back(rubbishpile);
}

void EntityManager::AddBlueCow(BlueCow* bluecow)
{
	m_blueCow.push_back(bluecow);
}

void EntityManager::AddHappyPill(HappyPill* happypill)
{
	m_happyPill.push_back(happypill);
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
		for(int i = 0; i < m_playerAttack.size(); i++)
		{
			m_playerAttack[0]->Update(deltatime);
		}
	}
	 
}

void EntityManager::DrawPlayer(sf::RenderWindow* window)
{
	if(m_player->GetBlueCowTimer() > 0.0)
	{
		window->draw(*m_player->GetBlueSprite());
	}
	if(m_player->GetHappyPillTimer() > 0.0)
	{
		window->draw(*m_player->GetHappySprite());
	}

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
					//m_soundManager->PlaySound("Pow");
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

//Melee attack - Update and Draw

void EntityManager::UpdateMeleeAttack(float &deltatime)
{
	if( !m_meleeAttacks.empty() )
	{
		for(unsigned int i = 0; i < m_meleeAttacks.size(); i++)
		{
			m_meleeAttacks[i]->Update(deltatime);
		}
	}
}

void EntityManager::DrawMeleeAttack(sf::RenderWindow* window)
{
	if( !m_meleeAttacks.empty() )
	{
		for(unsigned int i = 0; i < m_meleeAttacks.size(); i++)
		{
			window->draw(*m_meleeAttacks[i]->GetSprite());
		}
	}
}

//Enemy Melee - Update and Draw

void EntityManager::UpdateEnemyMelee(float &deltatime)
{
	if( !m_enemyMelee.empty() )
	{
		for(unsigned int i = 0; i < m_enemyMelee.size(); i++)
		{
			m_enemyMelee[i]->Update(deltatime, m_player->GetPosition());
			if(m_enemyMelee[i]->GetAttacking())
			{
				//AddMeleeAttack(//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			}

		}
	}
}

void EntityManager::DrawEnemyMelee(sf::RenderWindow* window)
{
	if( !m_enemyMelee.empty() )
	{
		for(unsigned int i = 0; i < m_enemyMelee.size(); i++)
		{
			if(m_enemyMelee[i]->isDead())
			{
				window->draw(*m_enemyMelee[i]->GetDeathSprite());
			}
			else if(!m_enemyMelee[i]->isDead())
			{
				if(!m_enemyMelee[i]->GetAttackAnimation())
				{
					window->draw(*m_enemyMelee[i]->GetSprite());
				}
				else if(m_enemyMelee[i]->GetAttackAnimation())
				{
					window->draw( *m_enemyMelee[i]->GetAttackSprite() );
				}
			}
		}
	}
}

//Bullet - Update and Draw

void EntityManager::UpdateBullet(float &deltatime)
{
	if(!m_bullets.empty())
	{
		for(unsigned int i = 0; i < m_bullets.size(); i++)
		{
			m_bullets[i]->Update(deltatime);
		}
	}
}

void EntityManager::DrawBullet(sf::RenderWindow* window)
{
	if(!m_bullets.empty())
	{
		for(unsigned int i = 0; i < m_bullets.size(); i++)
		{
			window->draw(*m_bullets[i]->GetSprite());
		}
	}

}

//Enemy Ranged - Update and Draw

void EntityManager::UpdateEnemyRanged(float &deltatime)
{
	if(!m_enemyRanged.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged.size(); i++)
		{
			m_enemyRanged[i]->Update(deltatime, m_player->GetPosition());
		}
	}
}

void EntityManager::DrawEnemyranged(sf::RenderWindow* window)
{
	if(!m_enemyRanged.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged.size(); i++)
		{
			if(m_enemyRanged[i]->isDead())
			{
				window->draw(*m_enemyRanged[i]->GetDeathSprite());
			}

			else if(!m_enemyRanged[i]->isDead())
			{
				if(m_enemyRanged[i]->GetAttackAnimation())
				{
					window->draw(*m_enemyRanged[i]->GetAttackSprite());
				}
				else if(!m_enemyRanged[i]->GetAttacking())
				{
					window->draw(*m_enemyRanged[i]->GetSprite());
				}
			}
		}
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
		}
	}
}

void EntityManager::DrawEnemyAOE(sf::RenderWindow* window)
{
	if( !m_enemyAOE.empty() )
	{
		for(unsigned int i = 0; i < m_enemyAOE.size(); i++)
		{
			if(m_enemyAOE[i]->isDead())
			{
				window->draw(*m_enemyAOE[i]->GetDeathSprite());
			}
			else
			{
				window->draw(*m_enemyAOE[i]->GetAttack()->GetSprite());
				window->draw(*m_enemyAOE[i]->GetSprite());
			}

		}
	}
}

//Enemy Ranged2 - Update and Draw

void EntityManager::UpdateEnemyRanged2(float &deltatime)
{
	if(!m_enemyRanged2.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged2.size(); i++)
		{
			m_enemyRanged2[i]->Update(deltatime, m_player->GetPosition());
		}
	}
}

void EntityManager::DrawEnemyranged2(sf::RenderWindow* window)
{
	if(!m_enemyRanged2.empty())
	{
		for(unsigned int i = 0; i < m_enemyRanged2.size(); i++)
		{
			if(m_enemyRanged2[i]->isDead())
			{
				window->draw(*m_enemyRanged2[i]->GetDeathSprite());
			}

			else if(!m_enemyRanged2[i]->isDead())
			{
				if(m_enemyRanged2[i]->GetAttackAnimation())
				{
					window->draw(*m_enemyRanged2[i]->GetAttackSprite());
				}
				else if(!m_enemyRanged2[i]->GetAttacking())
				{
					window->draw(*m_enemyRanged2[i]->GetSprite());
				}
			}
		}
	}
}

//Rubbish Bin Update and Draw

void EntityManager::UpdateRubbishBin(float &deltatime)
{
	if(!m_rubbishBin.empty())
	{
		for(unsigned int i = 0; i < m_rubbishBin.size(); i++)
		{
			m_rubbishBin[i]->Update(deltatime);
		}
	}
}

void EntityManager::DrawRubbishBin(sf::RenderWindow* window, float &deltatime, float &playerangle)
{
	if(!m_rubbishBin.empty())
	{
		for(unsigned int i = 0; i < m_rubbishBin.size(); i++)
		{
			if(!m_rubbishBin[i]->m_dead)
			{
				window->draw(*m_rubbishBin[i]->GetSprite());
			}
			else if(m_rubbishBin[i]->m_dead)
			{
				window->draw(*m_rubbishBin[i]->GetDeathSprite(deltatime, playerangle));
				//m_rubbishBin[i]->m_spawnedTrash = true;
			}
		}
	}
}

//Rubbish Pile Update and Draw

void EntityManager::UpdateRubbishPile(float &deltatime)
{
	if(!m_rubbishpile.empty())
	{
		for(unsigned int i = 0; i < m_rubbishpile.size(); i++)
		{
			m_rubbishpile[i]->Update(deltatime);
		}
	}
}

void EntityManager::DrawRubbishPile(sf::RenderWindow* window)
{
	if(!m_rubbishpile.empty())
	{
		for(unsigned int i = 0; i < m_rubbishpile.size(); i++)
		{
			window->draw(*m_rubbishpile[i]->GetAnimation());
		}
	}
}

//Blue Cow Update and Draw

void EntityManager::UpdateBlueCow(float &deltatime)
{
	if( !m_blueCow.empty() )
	{
		for(unsigned int i = 0; i < m_blueCow.size(); i++)
		{
			m_blueCow[i]->Update(deltatime);
		}
	}
}

void EntityManager::DrawBlueCow(sf::RenderWindow* window)
{
	if( !m_blueCow.empty() )
	{
		for(unsigned int i = 0; i < m_blueCow.size(); i++)
		{
			window->draw(*m_blueCow[i]->GetSprite());
		}
	}
}

//Happy Pill Update and Draw

void EntityManager::UpdateHappyPill(float &deltatime)
{
	if( !m_happyPill.empty() )
	{
		for(unsigned int i = 0; i < m_happyPill.size(); i++)
		{
			m_happyPill[i]->Update(deltatime);
		}
	}
}

void EntityManager::DrawHappyPill(sf::RenderWindow* window)
{
	if( !m_happyPill.empty() )
	{
		for(unsigned int i = 0; i < m_happyPill.size(); i++)
		{
			window->draw(*m_happyPill[i]->GetSprite());
		}
	}
}

//HUD - update and draw

void EntityManager::UpdateHUD(Player* player, float &deltatime)
{
	m_HUD->Update(player, deltatime);
}

void EntityManager::DrawHud(sf::RenderWindow* window) // window->draw(*m_HUD
{
	if(m_player->GetHP() <= 20)
	{
		window->draw(*m_HUD->GetWarningLeft());
	}
	else if(m_player->GetHP() >= 80)
	{
		window->draw(*m_HUD->GetWarningRight());
	}

	window->draw(*m_HUD->GetPowerupframe());
	window->draw(*m_HUD->GetPumpmeter());
	window->draw(*m_HUD->GetScoreSprite());

	window->draw(*m_HUD->GetIndicatorEffect());
	window->draw(*m_HUD->GetIndicator());

	if(m_player->m_blueCows > 0)
	{
		window->draw(*m_HUD->GetBlueCow());
	}
	if(m_player->m_happyPills > 0)
	{
		window->draw(*m_HUD->GetHappyPill());
	}

	if(m_HUD->GetBlueArrowTimer() < 4.0 && m_HUD->GetBlueArrowTimer() > 0.0)
	{
		window->draw(*m_HUD->GetBlueArrow());
	}

	if(m_HUD->GetRedArrowTimer() < 6.0 && m_HUD->GetRedArrowTimer() > 0.0)
	{
		window->draw(*m_HUD->GetRedArrow());
	}


	window->draw(*m_HUD->GetBlueCowText());
	window->draw(*m_HUD->GetHappyPillText());
	window->draw(*m_HUD->GetScoreText());
}