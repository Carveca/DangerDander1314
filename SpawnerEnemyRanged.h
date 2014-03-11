//Enemy Ranged Spawner header file

#pragma once

class EnemyRanged;
class SoundManager;

class SpawnerEnemyRanged
{
public:
	SpawnerEnemyRanged();
	SpawnerEnemyRanged(sf::Sprite* sprite, sf::Sprite* attacksprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager);
	~SpawnerEnemyRanged();

	EnemyRanged* Spawn();

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
};