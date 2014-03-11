//Spawner Enemy melee source file

#include "stdafx.h"
#include "SpawnerEnemyMelee.h"
#include "EnemyMelee.h"
#include "SoundManager.h"


SpawnerEnemyMelee::SpawnerEnemyMelee()
{

}

SpawnerEnemyMelee::SpawnerEnemyMelee(sf::Sprite* sprite, sf::Sprite* attacksprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager)
{
	 m_spawnTimer = 0.0f;	
	m_spawning = false;

	m_spawnPosition = spawnLocation;

	m_sprite = sprite;
	m_attackSprite = attacksprite;
	m_deathSprite = deathsprite;

	m_soundManager = soundmanager;

}

SpawnerEnemyMelee::~SpawnerEnemyMelee()
{

}

EnemyMelee* SpawnerEnemyMelee::Spawn()
{
	return new EnemyMelee(m_sprite, m_spawnPosition, m_attackSprite, m_deathSprite, m_soundManager);
}

void SpawnerEnemyMelee::Update(float &deltatime)
{
	m_spawning = false;

	m_spawnTimer += deltatime;

	if(m_spawnTimer >= 2.5)
	{
		m_spawnTimer = 0.0f;
		m_spawning = true;
	}

}

bool SpawnerEnemyMelee::GetSpawnState()
{
	return m_spawning;
}


	