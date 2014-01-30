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

void Entity::SetPosition(sf::Vector2f position)
{
	m_position = position;
}

sf::Vector2f Entity::GetPosition()
{
	return m_position;
}
