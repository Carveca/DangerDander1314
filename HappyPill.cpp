//HappyPill.cpp

#include "stdafx.h"
#include "HappyPill.h"
#include "Collider.h"


HappyPill::HappyPill(sf::Sprite* sprite, sf::Vector2f &position)
{
	m_hp = 1;
	m_speed = 100;

	m_extension.x = 64;
	m_extension.y = 64;
	m_position = position;
	m_name = "HappyPill";

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(30);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite->setOrigin(32,32);

	m_imageNR = 0;
	m_frameCounter = 0.0f;
}

HappyPill::~HappyPill()
{
	m_collisions.clear();

	delete m_collider;
	m_collider = nullptr;
}

void HappyPill::Update(float &elapsedTime)
{
	m_position.y += m_speed * elapsedTime;

	m_collider->SetPosition(m_position);
	
	m_sprite->setTextureRect(sf::IntRect( 33 * m_imageNR, 0, 32, 64));
	m_frameCounter += elapsedTime;
	if(m_frameCounter >= 0.1f)
	{
		m_imageNR++;
		m_frameCounter = 0.0f;
		if(m_imageNR > 6)
			m_imageNR = 0;
	}
	
	HandleCollision();
}

void HappyPill::HandleCollision()
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