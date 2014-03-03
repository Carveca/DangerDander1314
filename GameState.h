//GameState.h

#pragma once

#include "State.h"

class EntityManager;

class SpawnerAOEenemy;

class Player;

class GameState : public State{
public:
	GameState();

	bool Enter(StateManager* stateManager, SpriteManager* spriteManager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);
	std::string Next();
	bool IsType(const std::string &type);

	void Input();

private:
	
	StateManager*		m_stateManager;
	SpriteManager*		m_spriteManager;
	EntityManager*		m_entityManager;

	SpawnerAOEenemy*	m_spawnerAOEenemy;
	
	Level* m_levelTop;
	Level* m_levelBottom;
	
	Player* m_player;
	
	sf::Vector2f m_direction;
	float m_angle;


	bool m_done;
	std::string m_next_state;	

};