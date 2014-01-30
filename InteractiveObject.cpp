//Interactive Object source file

#include "InteractiveObject.h"
#include "Collider.h"

InteractiveObject::InteractiveObject()
{
	
	m_collider = nullptr;

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