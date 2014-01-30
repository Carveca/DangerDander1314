//Interactive Object header file

#pragma once

#include "Entity.h"
#include <vector>

class Collider;

class InteractiveObject : public Entity
{
public:
	InteractiveObject();
	~InteractiveObject();

	int GetHP();
	
	void HandleCollision();

	bool GetColliderCircle();

	Collider* GetCollider();

	void AddCollision(std::pair<InteractiveObject*, sf::Vector2f> collision_pair);

protected:
	int m_hp;
	float m_speed;
	bool m_collider_circle;

	Collider* m_collider;

	std::vector< std::pair<InteractiveObject*, sf::Vector2f> > m_collisions;

};