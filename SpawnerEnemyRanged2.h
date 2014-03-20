//Spawner Enemy Ranged Protester version header file

#pragma once

class EnemyRanged2;
class SoundManager;

class SpawnerEnemyRanged2
{
public:
	SpawnerEnemyRanged2();
	SpawnerEnemyRanged2(sf::Sprite* sprite, sf::Sprite* attacksprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager);
	~SpawnerEnemyRanged2();

	EnemyRanged2* Spawn();

	void Update(float &deltatime);

	bool GetSpawnState();

protected:
	float m_spawnTimer;
	
	bool m_spawning;

	sf::Vector2f m_spawnPosition;

	sf::Sprite* m_sprite;
	sf::Sprite* m_attackSprite;
	sf::Sprite* m_deathSprite;

	SoundManager* m_soundManager;
	FileReader* m_reader;
};