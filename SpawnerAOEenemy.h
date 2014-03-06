//AOEenemy Spawner header file

#pragma once

class EnemyAOE;

class SpawnerAOEenemy
{
public:
	SpawnerAOEenemy();
	SpawnerAOEenemy(sf::Sprite* sprite, sf::Sprite* AOEsprite, sf::Vector2f &spawnLocation);
	~SpawnerAOEenemy();

	EnemyAOE* Spawn();

	void Update(float &deltatime);

	bool GetSpawnState();

protected:
	float m_spawnTimer;
	
	bool m_spawning;

	sf::Vector2f m_spawnPosition;

	sf::Sprite* m_sprite;
	sf::Sprite* m_AOEsprite;
};