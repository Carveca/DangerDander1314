//GameState II header file

#pragma once

#include "StateII.h"

class EntityManager;

class SoundManager;

class SpawnerAOEenemy;
class SpawnerRubbishBin;
class SpawnerRubbishAndPower;
class SpawnerBullet;
class SpawnerEnemyRanged;
class SpawnerEnemyMelee;
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
	SpawnerBullet* m_spawnerBullet;
	SpawnerEnemyRanged* m_spawnerEnemyRanged;
	SpawnerEnemyMelee* m_spawnerEnemyMelee;

	SpawnerRubbishBin* m_spawnerRubbishBin;
	SpawnerRubbishBin* m_spawnerRubbishBin2;

	SpawnerRubbishAndPower* m_spawnerRubbishAndPower;

	sf::Sprite* m_pauseScreen;
	sf::Sprite* m_loadDone;
	
	Level* m_levelTop;
	Level* m_levelBottom;
	
	sf::Vector2f m_direction;
	float m_angle;

private:
	SpriteManager* m_spriteManager;
	FileReader m_reader;
	FileWriter m_writer;

	bool m_loading;
	bool m_loadingDone;

	bool m_paused;
	bool m_done;

	std::string m_nextState;

};