//MenuState II header File

#pragma once

#include "StateII.h"

class MenuStateII : public StateII
{
public:
	MenuStateII();

	bool Enter(SpriteManager* spritemanager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);

	std::string Next();
	bool IsType(const std::string &type);


private:
	//StateManager* m_stateManager;
	SpriteManager* m_spriteManager;

	bool m_done;
	std::string m_nextState;


};