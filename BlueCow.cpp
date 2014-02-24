//BlueCow.cpp

#include "stdafx.h"
#include "BlueCow.h"
#include "Collider.h"


BlueCow::BlueCow(sf::Sprite sprite, sf::Vector2f position)
{
	m_hp = 1;

	m_extension.x = 64;
	m_extension.y = 64;
	m_position = position;
	m_name = "BlueCow";

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(30);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite.setOrigin(32,32);

	m_imageNR = 0;
	m_frameCounter = 0.0f;

}

BlueCow::~BlueCow()
{
	m_collisions.clear();

	delete m_collider;
	m_collider = nullptr;
}

void BlueCow::Update(float elapsedTime)
{
	m_collider->SetPosition(m_position);
	m_sprite.setPosition(m_position);
	
	m_deltatime += elapsedTime;

	if(m_deltatime >= 0.01)
	{
		m_position.y += m_speed * m_deltatime;
		m_deltatime = 0.0f;
	}

	HandleCollision();


}

void BlueCow::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player")
		{
			m_hp--;
		}
	}
	m_collisions.clear();
}