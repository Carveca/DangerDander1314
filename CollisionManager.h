//CollisionManager header file

#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

class InteractiveObject;

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void Initialize();
	void Add(InteractiveObject* object);
	void Cleanup();
	void CheckCollision();
	
	sf::Vector2f OffsetBoxVsBox( );
	sf::Vector2f OffsetCircleVsCircle( );

private:
	
	std::vector<InteractiveObject*> m_vector_colliders;

};