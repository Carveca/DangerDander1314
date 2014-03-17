//MenuState II header File

#pragma once

#include "StateII.h"

class MenuStateII : public StateII
{
public:
	MenuStateII();

	bool Enter(SpriteManager* spritemanager, MusicManager* musicmanager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window, float &deltatime);

	std::string Next();
	bool IsType(const std::string &type);

private:
	//StateManager* m_stateManager;
	SpriteManager* m_spriteManager;
	MusicManager* m_musicManager;

	sf::Sprite* m_backGround;
	sf::CircleShape cursor;

	sf::Vector2f cursorPOS;

	float m_keytimer;
	int m_selection;
	bool m_done;
	std::string m_nextState;

};