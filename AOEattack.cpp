//AOEattack source file

#include "stdafx.h"
#include "AOEattack.h"
#include "Collider.h"

AOEattack::AOEattack()
{

}

AOEattack::AOEattack(sf::Sprite sprite, sf::Vector2f position)
{
	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;

	m_name = "AOEattack";

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(100);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_sprite = sprite;
	m_sprite.setOrigin(128, 128);
	
	m_imageNR = 0;
	m_frameCounter = 0.0f;
}

AOEattack::~AOEattack()
{

}

void AOEattack::Update()
{
	m_collider->SetPosition(m_position);	
}