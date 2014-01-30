//Collision Manager source file

#include "CollisionManager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::Initialize()
{

}

void CollisionManager::Add(InteractiveObject* object)
{
	m_vector_colliders.push_back( object );
}

void CollisionManager::Cleanup()
{

}

void CollisionManager::CheckCollision()
{

}

sf::Vector2f OffsetBoxVsBox( )
{
	sf::Vector2f offset;


	return offset;
}

sf::Vector2f OffsetCircleVsCircle( )
{
	sf::Vector2f offset;

	return offset;
}