//Rubbishpile.cpp

#include "stdafx.h"
#include "Rubbishpile.h"
#include "Collider.h"

Rubbishpile::Rubbishpile(sf::Sprite* sprite, sf::Vector2f &position, SoundManager* soundmanager, float &angle)
{
	m_name = "Rubbishpile";
	m_position = position;
	m_speed = 100;

	m_angle = angle;

	m_sprite = sprite;
	m_sprite->setOrigin(60, 60);
	m_sprite->setPosition(position);

	m_soundManager = soundmanager;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetPosition(position);
	m_collider->SetExtension(sf::Vector2f(120, 120));
	m_collider->SetRadius(60);

	m_imageNR = 0;
	m_frameCounter = 0.0f;

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
		
	//m_sprite->setTextureRect(sf::IntRect( 129 * m_imageNR, 0, 128, 128));
	m_frameCounter += deltatime;
	if(m_frameCounter >= 0.1f)
	{
		m_imageNR++;
		m_frameCounter = 0.0f;
		if(m_imageNR > 5)
			m_imageNR = 6;
	}
	

	HandleCollision();
}

void Rubbishpile::HandleCollision()
{
	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player")
		{
			m_hp -= 1;
		}
	}

	m_collisions.clear();
}

sf::Sprite* Rubbishpile::GetAnimation()
{
	m_sprite->setPosition(GetPosition());

	m_sprite->setTextureRect(sf::IntRect( 129 * m_imageNR, 0, 128, 128));

	m_sprite->setRotation(m_angle);

	return m_sprite;
}