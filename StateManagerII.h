//State Manager II Header File

#pragma once

#include <vector>

class StateII;
class SpriteManager;
class MusicManager;

class StateManagerII
{
public:
	StateManagerII();
	~StateManagerII();

	struct sf::RenderWindow* m_window;

	void Attach(StateII* state);
	void SetState(const std::string &type);
	void ChangeState();

	void Update(float &deltatime);
	void Draw();

private:
	std::vector<StateII*> m_states;

	StateII* m_current;
	SpriteManager* m_spriteManager;
	MusicManager* m_musicManager;

};