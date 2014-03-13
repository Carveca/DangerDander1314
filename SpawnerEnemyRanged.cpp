//Spawner Enemy Ranged source file

#include "stdafx.h"
#include "SpawnerEnemyRanged.h"
#include "EnemyRanged.h"
#include "SoundManager.h"


SpawnerEnemyRanged::SpawnerEnemyRanged()
{

}

SpawnerEnemyRanged::SpawnerEnemyRanged(sf::Sprite* sprite, sf::Sprite* attacksprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager)
{
	 m_spawnTimer = 0.0f;	
	m_spawning = false;

	m_spawnPosition = spawnLocation;

	m_sprite = sprite;
	m_attackSprite = attacksprite;
	m_deathSprite = deathsprite;

	m_soundManager = soundmanager;

	m_soundManager->LoadSound("gun.wav", "gun");
}

SpawnerEnemyRanged::~SpawnerEnemyRanged()
{

}

EnemyRanged* SpawnerEnemyRanged::Spawn()
{
	return new EnemyRanged(m_sprite, m_spawnPosition, m_attackSprite, m_deathSprite, m_soundManager);
}

void SpawnerEnemyRanged::Update(float &deltatime)
{
	m_spawning = false;

	m_spawnTimer += deltatime;

	if(m_spawnTimer >= 2.5)
	{
		m_spawnTimer = 0.0f;
		m_spawning = true;
	}

}

bool SpawnerEnemyRanged::GetSpawnState()
{
	return m_spawning;
}


	