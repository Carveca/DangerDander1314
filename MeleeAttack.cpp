//MeleeAttack.cpp

#include "stdafx.h"
#include "MeleeAttack.h"
#include "Collider.h"
#include "Player.h"

MeleeAttack::MeleeAttack(sf::Sprite* sprite ,sf::Vector2f position, SoundManager* soundmanager)
{
	m_name = "PlayerAttack";
	m_position = position;

	m_sprite = sprite;
	m_sprite->setOrigin(60, 60);
	m_sprite->setPosition(position);

	m_soundManager = soundmanager;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetPosition(position);
	m_collider->SetExtension(sf::Vector2f(120, 120));
	m_collider->SetRadius(100);

	m_life = 0.1f;
	m_dead = false;
}

MeleeAttack::~MeleeAttack()
{
	delete m_collider;
	m_collider = nullptr;
}

void MeleeAttack::Update(float &elapsedTime)
{
	m_sprite->setTextureRect(sf::IntRect(0, 0, 120, 120));
	
	m_sprite->setPosition(m_position);
	m_collider->SetPosition(m_position);

	m_life -= elapsedTime;

	if(m_life <= 0.0)
	{
		m_dead = true;
	}

	HandleCollision();
}

void MeleeAttack::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player")
		{
			m_player->ChangeHP(10);
		}
	}

	m_collisions.clear();
}

bool MeleeAttack::Dead()
{
	return m_dead;
}
