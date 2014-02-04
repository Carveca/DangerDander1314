//Player header file

#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();
	
	void Initialize();
	void Cleanup();	
	void Update();
	void HandleCollision();
	
	//move with arrow buttons, diagonal movement when two directional buttons are pressed , attack with space, switch weapon with q and e, power ups on 1,2 and 3.

private:

};