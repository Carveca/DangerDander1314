//Character header class

#pragma once

#include "InteractiveObject.h"

#include <SFML/System/Clock.hpp>

class Character : public InteractiveObject
{
public:
	Character();
	~Character();

	void MoveUp();
	void MoveUpRight();
	void MoveUpLeft();
	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void MoveDownRight();
	void MoveDownLeft();

protected:
	sf::Clock m_deltatime;

};