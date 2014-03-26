//OptionsState.h

#pragma once

#include "StateII.h"

class SpriteManager;
class MusicManager;
class Sprite;
class FileWriter;

class OptionsState : public StateII
{
public:
	OptionsState();

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
	FileWriter* m_writer;
	FileReader* m_reader;

	sf::Sprite* m_background;

	int m_musicVolume;
	int m_soundVolume;
	float m_keytimer;
	int m_selection;
	bool m_done;
	std::string m_nextState;
};