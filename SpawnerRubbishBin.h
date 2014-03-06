//Trash Bin Spawner header file

#pragma once

class RubbishBin;
class SoundManager;

class SpawnerRubbishBin
{
public:
	SpawnerRubbishBin();
	SpawnerRubbishBin(sf::Sprite* sprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager);
	~SpawnerRubbishBin();

	RubbishBin* Spawn();

	void Update(float &deltatime);

	bool GetSpawnState();

protected:
	float m_spawnTimer;
	
	bool m_spawning;

	sf::Vector2f m_spawnPosition;

	sf::Sprite* m_sprite;
	sf::Sprite* m_deathSprite;

	SoundManager* m_soundManager;
};