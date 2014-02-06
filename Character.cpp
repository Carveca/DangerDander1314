//Character source file
#include "stdafx.h"
#include "Character.h"


Character::Character() 
{
	m_deltatime = 0.0f;
}

Character::~Character()
{

}

void Character::Move(sf::Vector2f direction, float deltatime)
{
	m_deltatime = deltatime;

	m_position += direction * m_speed * m_deltatime;
	//m_position.x += direction.x * m_speed * 0.0001;
	//m_position.y += direction.y * m_speed * 0.0001;

}

