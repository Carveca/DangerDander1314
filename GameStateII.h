//GameState II header file

#pragma once

#include "StateII.h"

class EntityManager;
//class CollisionManager;

class SpawnerAOEenemy;
class Player;
class Level;

class GameStateII : public StateII
{
public:
	GameStateII();

	bool Enter(SpriteManager* spritemanager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);

	std::string Next();
	bool IsType(const std::string &type);

private:

	void Input();

private:
	EntityManager*		m_entityManager;

	SpawnerAOEenemy*	m_spawnerAOEenemy;
	
	Level* m_levelTop;
	Level* m_levelBottom;
	
	sf::Vector2f m_direction;
	float m_angle;

private:
	SpriteManager* m_spriteManager;
	//CollisionManager* m_collisionManager;

	bool m_done;
	std::string m_nextState;

};