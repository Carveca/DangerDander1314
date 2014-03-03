//Entity source file
#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(sf::Sprite* sprite, sf::Vector2f &position)
{
	m_name = "Name";
	m_position = position;
	m_sprite = sprite;
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

void Entity::Update(float &elapsedtime)
{

}

void Entity::SetName(std::string &name)
{
	m_name = name;
}

std::string Entity::GetName()
{
	return m_name;
}

void Entity::SetPosition(sf::Vector2f &position)
{
	m_position = position;
}

sf::Vector2f Entity::GetPosition()
{
	return m_position;
}

sf::Sprite* Entity::GetSprite()
{
	m_sprite->setPosition(m_position);

	return m_sprite;
}

sf::Vector2f Entity::GetExtension()
{
	return m_extension;
}