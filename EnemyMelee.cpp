//EnemyMelee source file
#include "stdafx.h"
#include "EnemyMelee.h"
#include "Collider.h"
#include "SoundManager.h"

#include <iostream>

EnemyMelee::EnemyMelee(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attackSprite, sf::Sprite* deathsprite, SoundManager* soundmanager)
{
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_points = 1;
	m_hp = m_reader->m_settings["EnemyMeleeHP"];
	m_isAttacking = false;
	m_attackAnimation = false;
	m_attackTimer = 0.0f;

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "EnemyMelee";
	m_speed = m_reader->m_settings["EnemyMeleeSpeed"];

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(m_reader->m_settings["EnemyMeleeRadius"]);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite->setOrigin(64, 64);
	
	m_attackSprite = attackSprite;
	m_attackSprite->setOrigin(64, 64);
	m_attackImageNR = 0;
	m_attackFrameCounter = 0.0f;

	m_deathSprite = deathsprite;
	m_deathSprite->setOrigin(64, 64);
	m_deathImageNR = 0;
	m_attackFrameCounter = 0.0f;

	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_Direction.y = 0;
	m_Direction.x = 0;

	m_dead = false;

	m_soundManager = soundmanager;
	m_soundManager->Initialize("../Sounds/");
	m_soundManager->LoadSound("melee.wav", "melee");
}

EnemyMelee::~EnemyMelee()
{
	delete m_collider;
	m_collider = nullptr;
}

void EnemyMelee::MeleeAttack()
{
	if(m_attackTimer <= 0)
	{
		m_attackTimer = 0.5;
		m_soundManager->PlaySound("melee");
	}
}

void EnemyMelee::Update(float &deltatime, sf::Vector2f refpos)
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
		float deltax = m_position.x - refpos.x;
		float deltay = m_position.y - refpos.y;
		float distance = sqrtf(deltax * deltax + deltay * deltay);
		float angle = atan2(deltay, deltax);
		m_Direction.x = cos(angle) * -1;
		m_Direction.y = sin(angle) * -1;
		m_isAttacking = false;

		if(distance > m_reader->m_settings["EnemyMeleeDistance"])
		{
			m_position += m_Direction * m_speed * deltatime;
		}
		else
		{	
			MeleeAttack();	
		}

		if(m_attackTimer <= 0.5 && m_attackTimer > 0.0)
		{
			m_attackAnimation = true;

			if(m_attackTimer <= 0.1 && m_attackTimer > 0.0)
			{
				m_isAttacking = true;		
				m_attackTimer = 0.0f;
			}
		}

		m_attackTimer -= deltatime;
		if(m_attackTimer < -1)
		{
			m_attackTimer = 0.0f;
		}	

		m_collider->SetPosition(m_position);
		m_sprite->setPosition(m_position);
		m_attackSprite->setPosition(m_position);

		m_sprite->setTextureRect(sf::IntRect( 129 * m_imageNR, 0, 128, 128));
		m_frameCounter += deltatime;

		//animation
		if(m_attackAnimation)
		{
			m_attackFrameCounter += deltatime;
			if(m_attackFrameCounter >= 0.1)
			{
				m_attackImageNR++;
				m_attackFrameCounter = 0.0f;

				if(m_attackImageNR > 4)
					m_attackImageNR = 0;
			}
		}
		else if(!m_attackAnimation && m_frameCounter >= 0.1f)
		{
			//reset attackanimation
			m_attackImageNR = 0;
			m_attackFrameCounter = 0.0f;

			//walk animation
			m_imageNR++;
			m_frameCounter = 0.0f;
			if(m_imageNR > 7)
				m_imageNR = 0;
		}	
	
		HandleCollision();

			//Bounds
		if(m_position.x < m_reader->m_settings["BoundsLeft"])
			m_position.x = m_reader->m_settings["BoundsLeft"];
		if(m_position.x > m_reader->m_settings["BoundsRight"])
			m_position.x = m_reader->m_settings["BoundsRight"];
		if(m_position.y < 0)
		{
			m_position.y = 0;
		}
		if(m_position.y > 1080)
		{
			m_position.y = 1080;
		}
	}
}

void EnemyMelee::HandleCollision()
{
	m_collider->SetPosition(GetPosition());
	bool selfcollision = false;

	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			m_hp -= 1;
		}
		if( m_collisions[i].first->GetName() == "EnemyMelee" )
		{
			if(!selfcollision)
			{
				selfcollision = true;
			}
			else if(selfcollision)
			{
				m_position = m_collisions[i].second;
			}			
		}
		else if( m_collisions[i].first->GetName() != "Bullet" && m_collisions[i].first->GetName() != "MeleeAttack")
		{
			m_position = m_collisions[i].second;
		}
	}
	
	m_collisions.clear();
}

bool EnemyMelee::GetAttacking()
{
	return m_isAttacking;
}

sf::Vector2f EnemyMelee::GetDirection()
{
	return m_Direction;
}

bool EnemyMelee::GetAttackAnimation()
{
	return m_attackAnimation;
}

sf::Sprite* EnemyMelee::GetAttackSprite()
{
	m_attackSprite->setPosition(GetPosition());

	m_attackSprite->setTextureRect( sf::IntRect(m_attackImageNR * 129, 0, 128, 128) );

	int turnangle = 0;
	if(m_Direction.x <= 1 && m_Direction.x > 0.2) //right
	{
		if(m_Direction.y <= 1 && m_Direction.y > 0.2) //down
		{
			turnangle = 315;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y > -0.2)
		{
			turnangle = 270;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y >= -1)// up
		{
			turnangle = 225;
		}
	}
	else if(m_Direction.x <= 0.2 && m_Direction.x > -0.2) //straight 
	{
		if(m_Direction.y <= 1 && m_Direction.y > 0.0)
		{
			turnangle = 0;
		}
		else if(m_Direction.y <= 0.0 && m_Direction.y >= -1)
		{
			turnangle = 180;
		}
	}
	else if(m_Direction.x <= -0.2 && m_Direction.x >= -1.0) //left
	{
		if(m_Direction.y <= 1 && m_Direction.y > 0.2) // down
		{
			turnangle = 45;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y > -0.2)
		{
			turnangle = 90;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y >= -1) // up
		{
			turnangle = 135;
		}
	}
	m_attackSprite->setRotation(turnangle);

	return m_attackSprite;
}

sf::Sprite* EnemyMelee::GetDeathSprite()
{
	m_deathSprite->setPosition(GetPosition());
	//m_deathSprite->setTextureRect(sf::IntRect(0, 0, 128, 128));
	return m_deathSprite;
}

sf::Sprite* EnemyMelee::GetSprite()
{
	m_sprite->setPosition(GetPosition());

	int turnangle = 0;
	if(m_Direction.x <= 1 && m_Direction.x > 0.2) //right
	{
		if(m_Direction.y <= 1 && m_Direction.y > 0.2) //down
		{
			turnangle = 315;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y > -0.2)
		{
			turnangle = 270;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y >= -1)// up
		{
			turnangle = 225;
		}
	}
	else if(m_Direction.x <= 0.2 && m_Direction.x > -0.2) //straight 
	{
		if(m_Direction.y <= 1 && m_Direction.y > 0.0)
		{
			turnangle = 0;
		}
		else if(m_Direction.y <= 0.0 && m_Direction.y >= -1)
		{
			turnangle = 180;
		}
	}
	else if(m_Direction.x <= -0.2 && m_Direction.x >= -1.0) //left
	{
		if(m_Direction.y <= 1 && m_Direction.y > 0.2) // down
		{
			turnangle = 45;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y > -0.2)
		{
			turnangle = 90;
		}
		else if(m_Direction.y <= 0.2 && m_Direction.y >= -1) // up
		{
			turnangle = 135;
		}
	}
	m_sprite->setRotation(turnangle);

	return m_sprite;
}
