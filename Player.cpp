//Player source file
#include "stdafx.h"
#include "Player.h"
#include "Collider.h"
#include "PlayerAttack.h"

#include <iostream>

Player::Player(sf::Sprite sprite, sf::Vector2f position) 
{
	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "Player";
	m_speed = 300.0f;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(60);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite.setOrigin(128, 128);
	
	m_imageNR = 0;
	m_frameCounter = 0.0f;
	
	m_attackTimer = 0.0f;
	m_weaponSize = 30;
	m_playerAttack = nullptr;
}

Player::~Player()
{

}

void Player::Initialize()
{

}

void Player::Cleanup()
{
	m_collisions.clear();
}

void Player::Update(float angle, sf::Vector2f direction, float elapsedtime)
{	
	Move(direction, elapsedtime);
	m_collider->SetPosition(m_position);
	m_sprite.setPosition(m_position);
	
	if(m_attackTimer == 0.5)
	{
		sf::Vector2f weaponPos = m_position;
		weaponPos.x += 30;
		weaponPos.y -= 30;
		m_playerAttack = new PlayerAttack(weaponPos, m_weaponSize);

		std::cout << "X: " << m_playerAttack->GetPosition().x << " Y: " << m_playerAttack->GetPosition().y << std::endl;
	}

	m_attackTimer -= elapsedtime;
	if(m_attackTimer < -10)
		m_attackTimer = 0.0f;

	//change frame
	m_sprite.setTextureRect(sf::IntRect( 256 * m_imageNR, 0, 256, 256));
	m_frameCounter += elapsedtime;
	if(m_frameCounter >= 0.1f)
	{
		m_imageNR++;
		m_frameCounter = 0.0f;
		if(m_imageNR > 7)
			m_imageNR = 0;
	}
	m_sprite.setRotation(angle);
		
	HandleCollision();

	if(m_position.x < 0)
		m_position.x = 0;

	if(m_position.y < 0)
		m_position.y = 0;

}

void Player::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player")
		{
			
		}

		if(m_collisions[i].first->GetName() == "EnemyMelee")
		{
			std::cout << "EnemyMelee Collision" << std::endl;
			m_position += m_collisions[i].second;
		}
	}
	
	m_collisions.clear();
}

sf::Sprite Player::GetSprite()
{
	return m_sprite;
}

void Player::Attack()
{
	if(m_attackTimer <= 0)
		m_attackTimer = 0.5;
}

float Player::GetAttackTimer()
{
	return m_attackTimer;
}

void Player::WeaponStick()
{
	m_weaponSize = 60;
}