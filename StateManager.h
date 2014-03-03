//StateManager.h

#pragma once

#include <vector>

class State;
class SpriteManager;

class StateManager
{

public:
	StateManager();
	~StateManager();

	struct sf::RenderWindow* m_window;
	
	bool Attach(State* state);
	void Update(float &deltatime);
	void Draw();

	void SetState(const std::string &type);
	void ChangeState();
	bool IsRunning();

private:
	std::vector<State*> m_states;

	State* m_current;
	SpriteManager* m_spriteManager;
};

