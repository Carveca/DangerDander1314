//Spawner Enemy Ranged protester version source file

#include "stdafx.h"
#include "SpawnerEnemyRanged2.h"
#include "EnemyRanged2.h"
#include "SoundManager.h"


SpawnerEnemyRanged2::SpawnerEnemyRanged2()
{

}

SpawnerEnemyRanged2::SpawnerEnemyRanged2(sf::Sprite* sprite, sf::Sprite* attacksprite, sf::Sprite* deathsprite, sf::Vector2f &spawnLocation, SoundManager* soundmanager)
{
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_spawnTimer = m_reader->m_settings["Ranged2SpawnerInitialTimer"];	
	m_spawning = false;

	m_spawnPosition = spawnLocation;

	m_sprite = sprite;
	m_attackSprite = attacksprite;
	m_deathSprite = deathsprite;

	m_soundManager = soundmanager;

	m_soundManager->LoadSound("throw.wav", "throw");
}

SpawnerEnemyRanged2::~SpawnerEnemyRanged2()
{

}

EnemyRanged2* SpawnerEnemyRanged2::Spawn()
{
	return new EnemyRanged2(m_sprite, m_spawnPosition, m_attackSprite, m_deathSprite, m_soundManager);
}

void SpawnerEnemyRanged2::Update(float &deltatime)
{
	m_spawning = false;

	m_spawnTimer += deltatime;

	if(m_spawnTimer >= m_reader->m_settings["Ranged2SpawnerTimer"])
	{
		m_spawnTimer = 0.0f;
		m_spawning = true;
	}

}

bool SpawnerEnemyRanged2::GetSpawnState()
{
	return m_spawning;
}
	