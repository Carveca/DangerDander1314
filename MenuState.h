#pragma once 

#include "State.h"

class MenuState : public State
{
public:
	MenuState();

	bool Enter(StateManager* stateManager, SpriteManager* spriteManager); 
	void Exit();
	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);
	std::string Next();
	bool IsType(const std::string &type);



private:		
	
	StateManager* m_stateManager;
	SpriteManager* m_spriteManager;

	//Menu sprites or pointer to menu class

	bool m_done;
	std::string m_next_state;	
};