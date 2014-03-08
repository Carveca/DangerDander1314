//AOEattack source file

#include "stdafx.h"
#include "AOEattack.h"
#include "Collider.h"

AOEattack::AOEattack()
{

}

AOEattack::AOEattack(sf::Sprite* sprite, sf::Vector2f &position, SoundManager* soundmanager)
{
	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;

	m_soundManager = soundmanager;

	m_name = "AOEattack";

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(128);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite->setPosition(m_position);
	m_sprite->setOrigin(128, 128);
	
	m_imageNR = 0;
	m_frameCounter = 0.0f;
}

AOEattack::~AOEattack()
{
	delete m_collider;
	m_collider = nullptr;
}

void AOEattack::Update(sf::Vector2f &position)
{
	m_position = position;
	m_sprite->setPosition(m_position);
	m_collider->SetPosition(m_position);	
}