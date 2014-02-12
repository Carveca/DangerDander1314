//CollisionManager header file

#pragma once
#include <vector>
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
	
	sf::Vector2f OffsetBoxVsBox();
	sf::Vector2f OffsetCircleVsCircle();

	std::vector<InteractiveObject*> GetColliders();

private:
	
	std::vector<InteractiveObject*> m_colliders;

};