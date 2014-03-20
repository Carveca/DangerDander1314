//Ranged enemy protester version source file

#include "stdafx.h"
#include "EnemyRanged2.h"
#include "SoundManager.h"
#include "Collider.h"

#include <cmath>

EnemyRanged2::EnemyRanged2(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attacksprite ,sf::Sprite* deathsprite, SoundManager* soundmanager)
{
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_points = 1;
	m_hp = m_reader->m_settings["EnemyRanged2HP"];
	m_isAttacking = false;
	m_attackAnimation = false;
	m_attackTimer = 0.0f;

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "EnemyRanged2";
	m_speed = m_reader->m_settings["EnemyRanged2Speed"];

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(m_reader->m_settings["EnemyRanged2Radius"]);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite->setOrigin(128, 128);
	
	m_attackSprite = attacksprite;
	m_attackSprite->setOrigin(128, 128);
	m_attackImageNR = 0;
	m_attackFrameCounter = 0.0f;

	m_deathSprite = deathsprite;
	m_deathSprite->setOrigin(64, 64);

	m_soundManager = soundmanager;

	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_Direction.y = 1;
	m_Direction.x = 0;

	m_dead = false;
}

EnemyRanged2::~EnemyRanged2()
{
	m_collisions.clear();

	delete m_collider;
	m_collider = nullptr;
}


void EnemyRanged2::Update(float &deltatime, sf::Vector2f refpos)
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
		if(m_position.y < 100)
		{
			m_position.y += m_Direction.y * m_speed * deltatime;
		}
		float deltax = m_position.x - refpos.x;
		float deltay = m_position.y - refpos.y;
		float distance = sqrtf(deltax * deltax + deltay * deltay);
		float angle = atan2(deltay, deltax);
		m_Direction.x = cos(angle) * -1;
		m_Direction.y = sin(angle) * -1;
	
		m_attackAnimation = false;
		m_isAttacking = false;

		if(distance > m_reader->m_settings["EnemyRanged2Distance"])
		{
			m_position += m_Direction * m_speed * deltatime;
		}
		else 
		{	
			RangedAttack();				
		}
	
		//
	
		if(m_attackTimer <= 0.5 && m_attackTimer > 0.0)
		{
			m_attackAnimation = true;

			if(m_attackTimer <= 0.1 && m_attackTimer > 0.0)
			{
				m_soundManager->PlaySound("throw");
				m_isAttacking = true;
				m_attackTimer = 0.0f;
			}
		}

		m_attackTimer -= deltatime;
		if(m_attackTimer < -1.0)
		{
			m_attackTimer = 0.0f;
		}	

		m_sprite->setTextureRect(sf::IntRect( 257 * m_imageNR, 0, 256, 256));
		m_frameCounter += deltatime;

		//animation
		if(m_attackAnimation)
		{
			m_attackFrameCounter += deltatime;
			if(m_attackFrameCounter >= 0.1)
			{
				m_attackImageNR++;
				m_attackFrameCounter = 0.0f;
				if(m_attackImageNR > 5)
					m_attackImageNR = 5;
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

		//X-Bounds
		if(m_position.x < m_reader->m_settings["BoundsLeft"])
			m_position.x = m_reader->m_settings["BoundsLeft"];
		if(m_position.x > m_reader->m_settings["BoundsRight"])
			m_position.x = m_reader->m_settings["BoundsRight"];
		//Y-Bounds
		if(m_position.y < -400)
		{
			m_position.y = 0;
		}
	}

}

void EnemyRanged2::HandleCollision()
{
	m_collider->SetPosition(GetPosition());

	bool selfcollision = false;

	for(int i = 0; i < m_collisions.size(); i++)
	{
	 	if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			m_hp -= 1;
		}
		
		else if(m_collisions[i].first->GetName() == "EnemyRanged2")
		{
			if(!selfcollision)
			{
				selfcollision = true;
			}
			else
			{
				m_position = m_collisions[i].second;
			}
		}
	}

	m_collisions.clear();

	//m_collider->SetPosition(GetPosition());
}

bool EnemyRanged2::GetAttacking()
{
	return m_isAttacking;
}

bool EnemyRanged2::GetAttackAnimation()
{
	return m_attackAnimation;
}

sf::Vector2f EnemyRanged2::GetDirection()
{
	return m_Direction;
}

void EnemyRanged2::RangedAttack()
{
	//m_soundManager->PlaySound("gun");

	if(m_attackTimer <= 0)
		m_attackTimer = 2.0;
}

sf::Sprite* EnemyRanged2::GetAttackSprite()
{
	m_attackSprite->setPosition(GetPosition());

	m_attackSprite->setTextureRect(sf::IntRect(m_attackImageNR * 257, 0, 256, 256));

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

sf::Sprite* EnemyRanged2::GetDeathSprite()
{
	m_deathSprite->setPosition(GetPosition());

	

	return m_deathSprite;
}

sf::Sprite* EnemyRanged2::GetSprite()
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