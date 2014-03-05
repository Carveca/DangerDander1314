//State II Header File

#pragma once

#include <string>
#include <iostream>

class SpriteManager;
class MusicManager;

class StateII
{
public:

	virtual ~StateII() {};
	
	virtual bool Enter(SpriteManager* spritemanager, MusicManager* musicmanager) = 0;
	virtual void Exit() = 0;

	virtual bool Update(float &deltatime) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;

	virtual std::string Next() = 0;
	virtual bool IsType(const std::string &type) = 0;

};