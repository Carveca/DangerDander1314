//Bullet.cpp

#include "stdafx.h"
#include "Bullet.h"
#include "Collider.h"

#include <iostream>

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Sprite* sprite, sf::Vector2f position, sf::Vector2f direction, SoundManager* soundmanager)
{
	m_hp = 1;

	m_extension.x = 32;
	m_extension.y = 32;
	m_position = position;
	m_speed = 400;

	m_soundManager = soundmanager;

	m_name = "Bullet";

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(32);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	if(sprite != nullptr)
	{
		m_sprite = sprite;
		m_sprite->setOrigin(32, 32);
	}
	else
	{
		std::cout << "Bullet Sprite fail" << std::endl;
	}
	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_Direction = direction;
}

Bullet::~Bullet()
{
	delete m_collider;
	m_collider = nullptr;
}

void Bullet::Update(float elapsedTime)
{
	m_position += m_Direction * m_speed * elapsedTime;

	m_collider->SetPosition(m_position);
	m_sprite->setPosition(m_position);

	HandleCollision();
}

void Bullet::HandleCollision()
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