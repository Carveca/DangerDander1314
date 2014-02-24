//Player Attack Source File

#include "stdafx.h"
#include "PlayerAttack.h"
#include "Collider.h"

PlayerAttack::PlayerAttack(sf::Sprite sprite, sf::Vector2f position, int size)
{
	m_name = "PlayerAttack";
	m_position = position;

	m_sprite = sprite;
	m_sprite.setOrigin(60, 60);
	m_sprite.setPosition(position);

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetPosition(position);
	m_collider->SetExtension(sf::Vector2f(120, 120));
	m_collider->SetRadius(size);

	m_life = 0.1f;
	m_dead = false;
	m_hit = false;
}

PlayerAttack::~PlayerAttack()
{
	delete m_collider;
	m_collider = nullptr;
}

void PlayerAttack::Update(float elapsedTime)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	
	m_life -= elapsedTime;

	if(m_life <= 0.0)
	{
		m_dead = true;
	}

	HandleCollision();
}

bool PlayerAttack::Dead()
{
	return m_dead;
}

void PlayerAttack::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() != "Player" && m_collisions[i].first->GetName() != "PlayerAttack" && m_collisions[i].first->GetName() != "AOEattack")
		{
			m_hit = true;
			break;
		}
	}

	m_collisions.clear();
}

bool PlayerAttack::GetHit()
{
	return m_hit;
}