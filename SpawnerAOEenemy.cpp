//AOEenemy Spawner Source File

#include "stdafx.h"
#include "SpawnerAOEenemy.h"
#include "EnemyAOE.h"
#include "SoundManager.h"

SpawnerAOEenemy::SpawnerAOEenemy()
{

}

SpawnerAOEenemy::SpawnerAOEenemy(sf::Sprite* sprite, sf::Sprite* AOEsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager)
{
	m_sprite = sprite;
	m_AOEsprite = AOEsprite;
	m_spawnPosition = spawnLocation;
	m_soundManager = soundmanager;

	m_spawnTimer = 3.0f;
	m_spawning = false;
}

SpawnerAOEenemy::~SpawnerAOEenemy()
{

}


EnemyAOE* SpawnerAOEenemy::Spawn()
{
	return new EnemyAOE(m_sprite, m_spawnPosition, m_AOEsprite, m_soundManager);	
}

void SpawnerAOEenemy::Update(float &deltatime)
{
	m_spawning = false;
	m_spawnTimer -= deltatime;

	if(m_spawnTimer <= 0.0)
	{
		m_spawning = true;
		m_spawnTimer = 1.0f;

		m_spawnPosition.x += 100;
		if(m_spawnPosition.x >= 1500)
			m_spawnPosition.x = 500;
	}
}

bool SpawnerAOEenemy::GetSpawnState()
{
	return m_spawning;
}