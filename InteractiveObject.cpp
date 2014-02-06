//Interactive Object source file
#include "stdafx.h"
#include "InteractiveObject.h"
#include "Collider.h"

InteractiveObject::InteractiveObject()
{
	m_speed = 1.0f;
	
	m_collider = nullptr;

	m_collider_circle = false;

	m_hp = 0;

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
	return m_collider_circle;
}

void InteractiveObject::AddCollision(std::pair<InteractiveObject*, sf::Vector2f> collision_pair)
{
	m_collisions.push_back(collision_pair);
}