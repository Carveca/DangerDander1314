//Player header file

#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player(sf::Sprite sprite);
	~Player();
	
	void Initialize();
	void Cleanup();	
	void Update();
	void HandleCollision();
	
	sf::Sprite GetSprite();
	
	//move with arrow buttons, diagonal movement when two directional buttons are pressed , attack with space, switch weapon with q and e, power ups on 1,2 and 3.

private:
	sf::Sprite m_sprite;
};