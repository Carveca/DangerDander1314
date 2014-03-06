//Game over sleep header file

#pragma once

#include "StateII.h"


class GameOverSleep : public StateII
{
public:
	GameOverSleep();

	bool Enter(SpriteManager* spritemanager, MusicManager* musicmanager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window, float &deltatime);

	std::string Next();
	bool IsType(const std::string &type);

private:
	SpriteManager* m_spriteManager;
	MusicManager* m_musicManager;

	sf::Sprite* m_backGround;
	
	bool m_done;
	std::string m_nextState;

};