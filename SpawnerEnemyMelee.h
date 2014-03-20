//Spawner Enemy Melee header file

#pragma once

class EnemyMelee;
class SoundManager;

class SpawnerEnemyMelee
{
public:
	SpawnerEnemyMelee();
	SpawnerEnemyMelee(sf::Sprite* sprite, sf::Sprite* attacksprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager);
	~SpawnerEnemyMelee();

	EnemyMelee* Spawn();

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