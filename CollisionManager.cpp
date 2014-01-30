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

	sf::Vector2f off;

	for( int object = 0; object < m_colliders.size(); object++)
	{
		for(int other = 0; other < m_colliders.size(); other++)
		{

			if( m_colliders[object]->GetColliderCircle() == false && m_colliders[other]->GetColliderCircle() == false )
			{

				if(m_colliders[object]->GetCollider()->OverlapBoxVsBox( m_colliders[other], off ))
				{
				
					std::pair<InteractiveObject*, sf::Vector2f> collision_pair;
					collision_pair = std::make_pair (m_colliders[object], off);
					m_colliders[object]->AddCollision(collision_pair);

				}

			}

			else if( m_colliders[object]->GetColliderCircle() == true && m_colliders[other]->GetColliderCircle() == true )
			{

				if(m_colliders[object]->GetCollider()->OverlapCircleVsCircle( m_colliders[other], off ))
				{

					std::pair<InteractiveObject*, sf::Vector2f> collision_pair;
					collision_pair = std::make_pair (m_colliders[object], off);
					m_colliders[object]->AddCollision(collision_pair);

				}

			}

			else
			{
				if(m_colliders[object]->GetCollider()->OverlapBoxVsBox( m_colliders[other], off ))
				{

					std::pair<InteractiveObject*, sf::Vector2f> collision_pair;
					collision_pair = std::make_pair (m_colliders[object], off);
					m_colliders[object]->AddCollision(collision_pair);
				}
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