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

void Character::Move(sf::Vector2f &direction, float &deltatime)
{
	m_position += direction * m_speed * deltatime;

	
}

