//Game over heart attack header file

#pragma once

#include "StateII.h"


class GameOverHeart : public StateII
{
public:
	GameOverHeart();

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