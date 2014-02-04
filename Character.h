//Character header class

#pragma once
#include "InteractiveObject.h"

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

	//method move med vector2 som parameter som är riktningen, antingen -1 eller 1. 

protected:
	sf::Clock m_deltatime;

};