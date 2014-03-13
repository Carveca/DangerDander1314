//EnemyRanged.cpp

#include "stdafx.h"
#include "EnemyRanged.h"
#include "SoundManager.h"
#include "Collider.h"

#include <cmath>

EnemyRanged::EnemyRanged(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attacksprite ,sf::Sprite* deathsprite, SoundManager* soundmanager)
{
	m_points = 1;
	m_hp = 1;
	m_isAttacking = false;
	m_attackAnimation = false;
	m_attackTimer = 0.0f;

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "EnemyRanged";
	m_speed = 250;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(40);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite->setOrigin(64, 64);
	
	m_attackSprite = attacksprite;
	m_attackSprite->setOrigin(64, 64);
	m_attackImageNR = 0;
	m_attackFrameCounter = 0.0f;

	m_deathSprite = deathsprite;
	m_deathSprite->setOrigin(64, 64);

	m_soundManager = soundmanager;

	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_Direction.y = 1;
	m_Direction.x = 0;
}

EnemyRanged::~EnemyRanged()
{
	m_collisions.clear();

	delete m_collider;
	m_collider = nullptr;
}


void EnemyRanged::Update(float &deltatime, sf::Vector2f refpos)
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

	if(distance > 400)
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
			m_soundManager->PlaySound("gun");
			m_isAttacking = true;
			m_attackTimer = 0.0f;
		}
	}

	m_attackTimer -= deltatime;
	if(m_attackTimer < -1.0)
	{
		m_attackTimer = 0.0f;
	}	

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
	if(m_position.x < 360)
		m_position.x = 360;
	if(m_position.x > 1560)
		m_position.x = 1560;
	//Y-Bounds
	if(m_position.y < -400)
	{
		m_position.y = 0;
	}

	//m_collider->SetPosition(m_position);
	//m_sprite->setPosition(m_position);
	//m_sprite->setRotation(angle);

	// ^ seriously WTF? ^
}

void EnemyRanged::HandleCollision()
{
	m_collider->SetPosition(GetPosition());

	bool selfcollision = false;

	for(int i = 0; i < m_collisions.size(); i++)
	{
	 	if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			m_hp -= 1;
		}
		
		else if(m_collisions[i].first->GetName() == "EnemyRanged")
		{
			if(!selfcollision)
			{
				selfcollision = true;
			}
			else
			{
				//float newposX = m_collisions[i].second.x / 2;
				//float newposY = m_collisions[i].second.y / 2;

				//m_position.x = newposX;
				//m_position.y = newposY;

				m_position = m_collisions[i].second;
			}
		}
		
	}

	m_collisions.clear();

	//m_collider->SetPosition(GetPosition());
}

bool EnemyRanged::GetAttacking()
{
	return m_isAttacking;
}

bool EnemyRanged::GetAttackAnimation()
{
	return m_attackAnimation;
}

sf::Vector2f EnemyRanged::GetDirection()
{
	return m_Direction;
}

void EnemyRanged::RangedAttack()
{
	//m_soundManager->PlaySound("gun");

	if(m_attackTimer <= 0)
		m_attackTimer = 5.0;
}

sf::Sprite* EnemyRanged::GetAttackSprite()
{
	m_attackSprite->setPosition(GetPosition());

	m_attackSprite->setTextureRect(sf::IntRect(m_attackImageNR * 129, 0, 128, 128));

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

sf::Sprite* EnemyRanged::GetDeathSprite()
{
	m_deathSprite->setPosition(GetPosition());

	

	return m_deathSprite;
}

sf::Sprite* EnemyRanged::GetSprite()
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