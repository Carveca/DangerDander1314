//Player Attack Source File

#include "stdafx.h"
#include "PlayerAttack.h"
#include "Collider.h"

PlayerAttack::PlayerAttack(sf::Vector2f position, int size)
{
	m_position = position;
	m_collider = new Collider;
	m_collider->SetPosition(position);
	m_collider->SetRadius(size);
	m_life = 0.5f;
}

PlayerAttack::~PlayerAttack()
{

}

void PlayerAttack::Update(float elapsedTime)
{
	m_life -= elapsedTime;

	if(m_life <= 0.0)
	{
		//delete
	}
}