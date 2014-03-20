//Interactive Object source file
#include "stdafx.h"
#include "InteractiveObject.h"
#include "Collider.h"

InteractiveObject::InteractiveObject()
{
	m_speed = 100.0f;
	
	m_collider = nullptr;

	m_colliderCircle = true;

	m_hp = 1;

	m_deathTimer = 0.5f;
	m_deathImageNR = 0;
	m_deathFrameCounter = 0.0f;
}

InteractiveObject::~InteractiveObject()
{

}

int InteractiveObject::GetHP()
{
	return m_hp;
}

void InteractiveObject::HandleCollision()
{

}

Collider* InteractiveObject::GetCollider()
{
	return m_collider;
}

bool InteractiveObject::GetColliderCircle()
{
	return m_colliderCircle;
}

void InteractiveObject::AddCollision(std::pair<InteractiveObject*, sf::Vector2f> &collision_pair)
{
	m_collisions.push_back(collision_pair);
}

bool InteractiveObject::isDead()
{
	return m_dead;
}

void InteractiveObject::Dead()
{
	m_dead = true;
}

float InteractiveObject::GetDeathTimer()
{
	return m_deathTimer;
}