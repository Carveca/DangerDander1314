//Collision Manager source file

#include "CollisionManager.h"
#include "InteractiveObject.h"
#include "Collider.h"

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
	m_colliders.push_back( object );
}

void CollisionManager::Cleanup()
{
	m_colliders.clear();
}

void CollisionManager::CheckCollision()
{
	m_colliders.clear();

	for( int checker = 0; checker < m_colliders.size(); checker++)
	{
		for(int checked = 0; checked < m_colliders.size(); checked++)
		{

			if( m_colliders[checker]->GetColliderCircle() == false && m_colliders[checked]->GetColliderCircle() == false )
			{

				m_colliders[checker]->GetCollider()->OverlapBoxVsBox( m_colliders[checked] );

			}

			else if( m_colliders[checker]->GetColliderCircle() == true && m_colliders[checked]->GetColliderCircle() == true )
			{
				m_colliders[checker]->GetCollider()->OverlapCircleVsCircle( m_colliders[checked] );
			}

			else
			{
				m_colliders[checker]->GetCollider()->OverlapBoxVsBox( m_colliders[checked] );
			}


		}
		
	}

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