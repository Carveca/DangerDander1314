//Character header class

#pragma once
#include "InteractiveObject.h"

class Character : public InteractiveObject
{
public:
	Character();
	~Character();
	
	void Move(sf::Vector2f direction, float deltatime);

protected:
	float m_deltatime;

};