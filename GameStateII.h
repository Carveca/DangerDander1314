//GameState II header file

#pragma once

#include "StateII.h"

class EntityManager;

class SoundManager;

class SpawnerAOEenemy;
class SpawnerRubbishBin;
class SpawnerRubbishAndPower;
class Player;
class Level;

/*
Singleton
class Foo;

static Foo* instance;


Foo::GetInstance()

Getinstance()	{
	if(instance != nullptr)	{
		return new Foo
	}
	else
	{
		return instance;
	}
}
*/

class GameStateII : public StateII
{
public:
	GameStateII();

	bool Enter(SpriteManager* spritemanager, MusicManager* musicmanager);
	void Exit();

	bool Update(float &deltatime);
	void Draw(sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window, float &deltatime);

	std::string Next();
	bool IsType(const std::string &type);

	

private:

	void Input();
	void GameOver();
	void GamePause();
	void RealTime(float &deltatime);

private:
	EntityManager* m_entityManager;
	MusicManager* m_musicManager;

	SoundManager* m_soundManager;

	SpawnerAOEenemy* m_spawnerAOEenemy;
	SpawnerRubbishBin* m_spawnerRubbishBin;
	SpawnerRubbishAndPower* m_spawnerRubbishAndPower;
	
	Level* m_levelTop;
	Level* m_levelBottom;
	
	sf::Vector2f m_direction;
	float m_angle;

private:
	SpriteManager* m_spriteManager;

	bool m_paused;
	bool m_done;
	std::string m_nextState;

};