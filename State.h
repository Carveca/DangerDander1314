//State.h

#pragma once

#include<string>

class StateManager;
class SpriteManager;

class Level;

class State 
{

public:
	virtual ~State() {};
	
	virtual bool Enter(StateManager* stateManager, SpriteManager* spriteManager)= 0;
	virtual void Exit()= 0;
	virtual bool Update(float &deltatime)=0;
	virtual void Draw(sf::RenderWindow* window)=0;
	virtual std::string Next()=0;
	virtual bool IsType(const std::string &type)=0;
};