//Character source file

#include "Character.h"


Character::Character()
{
	m_speed = 100.0f;
	

}

Character::~Character()
{

}

void Character::MoveUp()
{
	m_position.y -= 1;
}

void Character::MoveUpRight()
{
	m_position.x += 1;
	m_position.y -= 1;
}

void Character::MoveUpLeft()
{
	m_position.x -= 1;
	m_position.y -= 1;
}

void Character::MoveRight()
{
	m_position.x += 1;
}

void Character::MoveLeft()
{
	m_position.x -= 1;
}

void Character::MoveDown()
{
	m_position.y += 1;
}

void Character::MoveDownRight()
{
	m_position.x += 1;
	m_position.y += 1;
}

void Character::MoveDownLeft()
{
	m_position.x -= 1;
	m_position.y += 1;
}