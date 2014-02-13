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
}

PlayerAttack::~PlayerAttack()
{

}

void PlayerAttack::Update(float elapsedTime)
{
	m_sprite.setPosition(m_position);
	m_collider->SetPosition(m_position);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	
	m_life -= elapsedTime;

	if(m_life <= 0.0)
	{
		m_dead = true;
	}
}

bool PlayerAttack::Dead()
{
	return m_dead;
}