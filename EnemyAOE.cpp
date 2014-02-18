//EnemyAOE.cpp

#include "stdafx.h"
#include "EnemyAOE.h"
#include "Collider.h"
#include "AOEattack.h"


EnemyAOE::EnemyAOE(sf::Sprite sprite, sf::Vector2f position)
{
	m_points = 1;
	m_hp = 1;

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;
	m_name = "EnemyAOE";
	m_speed = 300;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(60);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_attack = new AOEattack; //?

	m_sprite = sprite;
	m_sprite.setOrigin(64, 64);
	
	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_yDirection = -1;
}

EnemyAOE::~EnemyAOE()
{
	m_collisions.clear();
}

void EnemyAOE::Attack()
{

}

void EnemyAOE::Update(float elapsedTime)
{
	m_deltatime += elapsedTime;

	if(m_deltatime >= 0.01)
	{
		m_position.y += m_yDirection * m_speed * m_deltatime;
		m_deltatime = 0.0f;
	}

	m_collider->SetPosition(m_position);
	m_sprite.setPosition(m_position);

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

		//Bounds
	if(m_position.x < 0)
		m_position.x = 0;
	if(m_position.x > 1920)
		m_position.x = 1920;
	if(m_position.y < 0)
	{
		m_position.y = 0;
		m_yDirection = -m_yDirection;
		m_sprite.rotate(180);
	}
	if(m_position.y > 1080)
	{
		m_position.y = 1080;
		m_yDirection = -m_yDirection;
		m_sprite.rotate(180);
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
	}

	m_collisions.clear();
}

AOEattack* EnemyAOE::GetAttack()
{
	return m_attack;
}