//Rubbishpile.cpp

#include "stdafx.h"
#include "Rubbishpile.h"
#include "Collider.h"

Rubbishpile::Rubbishpile(sf::Sprite* sprite, sf::Vector2f &position)
{
	m_name = "Rubbishpile";
	m_position = position;
	m_speed = 100;

	m_sprite = sprite;
	m_sprite->setOrigin(60, 60);
	m_sprite->setPosition(position);

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetPosition(position);
	m_collider->SetExtension(sf::Vector2f(120, 120));
	m_collider->SetRadius(60);
}

Rubbishpile::~Rubbishpile()
{
	delete m_collider;
	m_collider = nullptr;
}

void Rubbishpile::Update(float &deltatime)
{
	m_position.y += deltatime * m_speed;

	m_collider->SetPosition(m_position);

	HandleCollision();
}

void Rubbishpile::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player")
		{
			
		}
	}

	m_collisions.clear();
}