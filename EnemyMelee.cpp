//EnemyMelee source file
#include "stdafx.h"
#include "EnemyMelee.h"
#include "Collider.h"
#include "SoundManager.h"

#include <iostream>

EnemyMelee::EnemyMelee(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attackSprite, sf::Sprite* deathsprite, SoundManager* soundmanager)
{
	m_points = 1;
	m_hp = 1;
	m_isAttacking = false;
	m_attackAnimation = false;
	m_attackTimer = 0.0f;

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "EnemyMelee";
	m_speed = 300;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(60);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite->setOrigin(64, 64);
	
	m_attackSprite = attackSprite;
	m_attackSprite->setOrigin(128, 128);
	m_attackImageNR = 0;
	m_attackFrameCounter = 0.0f;

	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_Direction.y = 0;
	m_Direction.x = 0;
}

EnemyMelee::~EnemyMelee()
{
	delete m_collider;
	m_collider = nullptr;
}

void EnemyMelee::MeleeAttack()
{
	if(m_attackTimer <= 0)
		m_attackTimer = 0.3;
}

void EnemyMelee::Update(float &deltatime, sf::Vector2f refpos)
{
	float deltax = m_position.x - refpos.x;
	float deltay = m_position.y - refpos.y;
	float distance = sqrtf(deltax * deltax + deltay * deltay);
	float angle = atan2(deltay, deltax);
	m_Direction.x = cos(angle) * -1;
	m_Direction.y = sin(angle) * -1;
	m_isAttacking = false;

	if(distance > 100)
	{
		m_position += m_Direction * m_speed * deltatime;
	}
	else 
	{	
		MeleeAttack();				
	}

	if(m_attackTimer <= 0.3 && m_attackTimer > 0.0)
	{
		m_attackAnimation = true;

		if(m_attackTimer <= 0.2 && m_attackTimer > 0.0)
			m_isAttacking = true;		
	}

	m_attackTimer -= deltatime;
	if(m_attackTimer < -10)
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

		//Bounds
	if(m_position.x < 0)
		m_position.x = 0;
	if(m_position.x > 1920)
		m_position.x = 1920;
	if(m_position.y < 0)
	{
		m_position.y = 0;
	}
	if(m_position.y > 1080)
	{
		m_position.y = 1080;
	}
}

void EnemyMelee::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			m_hp -= 1;
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
	return m_attackSprite;
}

sf::Sprite* EnemyMelee::GetSprite()
{
	return m_sprite;
}