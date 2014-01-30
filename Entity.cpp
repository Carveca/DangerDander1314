//Entity source file

#include "Entity.h"
#include <SFML/System.hpp>

Entity::Entity()
{
	m_name = "Name";
}

Entity::~Entity()
{

}

void Entity::Initialize()
{
	
}

void Entity::Cleanup()
{

}

void Entity::Update()
{

}

void Entity::SetName(std::string name)
{
	m_name = name;
}

std::string Entity::GetName()
{
	return m_name;
}



sf::Vector2f Entity::GetPosition()
{
	return m_position;
}
