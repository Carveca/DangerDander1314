//HighscoreState.h

#pragma once

#include "StateII.h"

class SpriteManager;
class MusicManager;
class Sprite;

class HighscoreState : public StateII
{
public:
	HighscoreState();

	bool Enter(SpriteManager* spritemanager, MusicManager* musicmanager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window, float &deltatime);

	std::string Next();
	bool IsType(const std::string &type);

protected:
	SpriteManager* m_spriteManager;
	MusicManager* m_musicManager;

	sf::Sprite* m_background;

	bool m_done;
	std::string m_nextState;
};