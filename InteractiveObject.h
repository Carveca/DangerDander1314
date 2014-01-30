//Interactive Object header file

#pragma once

#include "Entity.h"

class Collider;

class InteractiveObject : public Entity
{
public:
	InteractiveObject();
	~InteractiveObject();

	int GetHP();
	
	void HandleCollision();

	Collider* GetCollider();

protected:
	int m_hp;

	float m_speed;

	Collider* m_collider;

};