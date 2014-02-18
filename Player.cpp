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
	m_hp = 90;
	m_hpDrain = -1;

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
	m_drainTimer = 0.0f;

	m_weaponSize = 60;
	m_isAttacking = false;
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
	//Move
	Move(direction, elapsedtime);
	m_collider->SetPosition(m_position);
	m_sprite.setPosition(m_position);
	
	//Attack
	m_isAttacking = false;

	if(m_attackTimer <= 0.2 && m_attackTimer > 0.0)
		m_isAttacking = true;
	
	m_attackTimer -= elapsedtime;
	if(m_attackTimer < -10)
		m_attackTimer = 0.0f;

	//Sprite
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
		
	//Collision
	HandleCollision();

	//HP
	m_drainTimer += elapsedtime;
	if(m_drainTimer >= 1.0)
	{
		m_hp += m_hpDrain;
		m_drainTimer = 0.0;

		m_hpDrain = -1;
	}
	
	//Bounds
	if(m_position.x < 280)
		m_position.x = 280;
	if(m_position.x > 1640)
		m_position.x = 1640;
	if(m_position.y < 0)
		m_position.y = 0;
	if(m_position.y > 1080)
		m_position.y = 1080;
}

void Player::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player")
		{
			
		}

		else if(m_collisions[i].first->GetName() == "EnemyMelee")
		{
			m_position += m_collisions[i].second;
		}

		else if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			m_position += m_collisions[i].second;
		}

		else if(m_collisions[i].first->GetName() == "AOEattack")
		{
			m_hpDrain = 1;
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
		m_attackTimer = 0.3;
}

float Player::GetAttackTimer()
{
	return m_attackTimer;
}

void Player::WeaponStick()
{
	m_weaponSize = 120;
}

bool Player::GetAttacking()
{
	return m_isAttacking;
}

int Player::GetWeaponSize()
{
	return m_weaponSize;
}

void Player::ChangeHP(int value)
{
	m_hp += value;

	if(m_hp > 100)
		m_hp = 100;
	else if(m_hp < 0)
		m_hp = 0;
}