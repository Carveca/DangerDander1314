//Interactive Object header file

#pragma once

#include "Entity.h"
#include <vector>
class Collider;
class AOEattack;

class InteractiveObject : public Entity
{
public:
	InteractiveObject();
	~InteractiveObject();

	virtual int GetHP();
	
	virtual void HandleCollision();

	virtual bool GetColliderCircle();

	virtual Collider* GetCollider();

	virtual void AddCollision(std::pair<InteractiveObject*, sf::Vector2f> &collision_pair);

	virtual bool isDead();
	virtual void Dead();

	float GetDeathTimer();

	//virtual AOEattack* GetAttack();

protected:
	Entity* m_parent;

	int m_hp;

	bool m_dead;
	float m_deathTimer;
	int m_deathImageNR;
	float m_deathFrameCounter;

	float m_speed;
	bool m_colliderCircle;

	Collider* m_collider;

	std::vector< std::pair<InteractiveObject*, sf::Vector2f> > m_collisions;

};