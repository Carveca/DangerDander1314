//GameState.h

#pragma once

#include "State.h"


class GameState : public State{
public:
	GameState();

	bool Enter();
	bool Update(float deltatime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &type);

private:
	bool m_done;
	std::string m_next_state;

};