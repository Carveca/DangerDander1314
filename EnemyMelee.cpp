//EnemyMelee source file
#include "stdafx.h"
#include "EnemyMelee.h"
#include "Collider.h"

#include <iostream>

EnemyMelee::EnemyMelee(sf::Sprite sprite, sf::Vector2f position)
{
	m_points = 1;
	m_hp = 1;

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
	m_sprite.setOrigin(64, 64);
	
	m_imageNR = 0;
	m_frameCounter = 0.0f;
}

EnemyMelee::~EnemyMelee()
{

}

void EnemyMelee::MeleeAttack()
{

}

void EnemyMelee::Update(float elapsedTime)
{
	m_collider->SetPosition(GetPosition());
	m_sprite.setPosition(GetPosition());

	m_sprite.setTextureRect(sf::IntRect( 128 * m_imageNR, 0, 128, 128));
	m_frameCounter += elapsedTime;
	if(m_frameCounter >= 0.1f)
	{
		m_imageNR++;
		m_frameCounter = 0.0f;
		if(m_imageNR > 7)
			m_imageNR = 0;
	}
	
	

	HandleCollision();
}

void EnemyMelee::HandleCollision()
{

}