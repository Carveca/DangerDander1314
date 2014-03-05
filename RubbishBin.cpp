//Rubbis Bin source file

#include "stdafx.h"
#include "RubbishBin.h"
#include "Collider.h"

RubbishBin::RubbishBin(sf::Sprite* binSprite, sf::Sprite* binDeathSprite, sf::Vector2f &position, SoundManager* soundmanager)
{
	m_hp = 1;
	m_speed = 100;

	m_position = position;
	m_extension = sf::Vector2f(128, 128);
	m_soundManager = soundmanager;

	m_sprite = binSprite;
	m_sprite->setPosition(GetPosition());
	m_sprite->setOrigin(64, 64);

	m_deathSprite = binDeathSprite;
	m_sprite->setPosition(GetPosition());
	m_sprite->setOrigin(64, 64);

	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_collider = new Collider;
	m_collider->SetPosition(GetPosition());
	m_collider->SetExtension(GetExtension());
	m_collider->SetRadius(60);
	m_colliderCircle = true;
	
}

RubbishBin::~RubbishBin()
{

}

void RubbishBin::Update(float &deltatime)
{
	m_position.y += m_speed * deltatime;
	
	HandleCollision();

}



void RubbishBin::DeathAnimation(float &deltatime)
{
	m_deathSprite->setPosition(GetPosition());

	m_deathSprite->setTextureRect(sf::IntRect( 128 * m_imageNR, 0, 128, 128));
	m_frameCounter += deltatime;
	if(m_frameCounter >= 0.1f)
	{
		m_imageNR++;
		m_frameCounter = 0.0f;
		if(m_imageNR > 4)
			m_imageNR = 0;
	}

}

void RubbishBin::HandleCollision()
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