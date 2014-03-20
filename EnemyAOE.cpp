//EnemyAOE.cpp

#include "stdafx.h"
#include "EnemyAOE.h"
#include "Collider.h"
#include "AOEattack.h"
#include "SoundManager.h"


EnemyAOE::EnemyAOE(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attacksprite, sf::Sprite* deathsprite, SoundManager* soundmanager)
{
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_points = 1;
	m_hp = m_reader->m_settings["EnemyAOEHP"];

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "EnemyAOE";
	m_speed = m_reader->m_settings["EnemyAOESpeed"];

	m_soundManager = soundmanager;
	//m_soundManager->LoadSound("aoe_attack.wav", "AOE");

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(m_reader->m_settings["EnemyAOERadius"]);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_attack = new AOEattack(attacksprite, m_position, m_soundManager); 

	m_sprite = sprite;
	m_sprite->setPosition(m_position);
	m_sprite->setOrigin(128, 128);
	
	m_deathSprite = deathsprite;
	m_deathSprite->setOrigin(64, 64);
	
	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_yDirection = 1;
	m_xDirection = 0;
	m_moveTimer = 1.0f;
	m_dead = false;
}

EnemyAOE::~EnemyAOE()
{
	m_collisions.clear();

	delete m_collider;
	m_collider = nullptr;
	
}

void EnemyAOE::Attack()
{

}

void EnemyAOE::Update(float &deltatime)
{
	if(m_dead)
	{
		m_position.y += 1 * 100 * deltatime;
		m_deathTimer -= deltatime;

		m_deathFrameCounter += deltatime;
		if(m_deathFrameCounter >= 0.1)
		{
			m_deathFrameCounter = 0.0f;
			m_deathImageNR++;
			if(m_deathImageNR > 5)
				m_deathImageNR = 0;
		}
		m_deathSprite->setTextureRect(sf::IntRect(m_deathImageNR * 129, 0, 128, 128));
	}
	else if(!m_dead)
	{
		//Movement
		m_position.y += m_yDirection * m_speed * deltatime;

		m_moveTimer -= deltatime;
		if(m_moveTimer <= 0.0)
		{
			unsigned int randomize = rand() % 100 +1;
			if(randomize <= 100 && randomize >= 67)
			{
				m_xDirection = 1;

			}
			else if(randomize <= 66 && randomize >= 34)
			{
				m_xDirection = -1;

			}
			else if(randomize <= 33 && randomize >= 1)
			{
				m_xDirection = 0;

			}

			m_moveTimer = 1.0;

		}
		m_position.x += m_xDirection * m_speed * 1.5 * deltatime;
		
		m_collider->SetPosition(m_position);

		//Sprite	
	
		m_sprite->setTextureRect(sf::IntRect( 256 * m_imageNR, 0, 256, 256));
		m_frameCounter += deltatime;
		if(m_frameCounter >= 0.1f)
		{
			m_imageNR++;
			m_frameCounter = 0.0f;
			if(m_imageNR > 7)
				m_imageNR = 0;
		}
	
		HandleCollision();

		//X-Bounds
		if(m_position.x < m_reader->m_settings["BoundsLeft"])
			m_position.x = m_reader->m_settings["BoundsLeft"];
		else if(m_position.x > m_reader->m_settings["BoundsRight"])
			m_position.x = m_reader->m_settings["BoundsRight"];
		//Y-Bounds
		if(m_position.y < -400)
		{
			m_position.y = 0;
		}

		m_sprite->setPosition(m_position);

		//attack
		m_attack->Update(m_position);
	}
}

void EnemyAOE::HandleCollision()
{
	for(int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			m_hp -= 1;
		}
		else if(m_collisions[i].first->GetName() != "EnemyAOE" && m_collisions[i].first->GetName() != "AOEattack")
		{
			m_position = m_collisions[i].second;
		}
	}

	m_collisions.clear();
}

AOEattack* EnemyAOE::GetAttack()
{
	return m_attack;
}

sf::Sprite* EnemyAOE::GetDeathSprite()
{
	m_deathSprite->setPosition(GetPosition());
	return m_deathSprite;
}