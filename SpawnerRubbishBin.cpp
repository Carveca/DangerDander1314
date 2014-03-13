//Spawner Trash Bin Source file

#include "stdafx.h"
#include "SpawnerRubbishBin.h"
#include "RubbishBin.h"
#include "SoundManager.h"

SpawnerRubbishBin::SpawnerRubbishBin()
{

}

SpawnerRubbishBin::SpawnerRubbishBin(sf::Sprite* sprite, sf::Sprite* deathsprite, sf::Vector2f &spawnlocation, SoundManager* soundmanager)
{
	m_sprite = sprite;
	m_deathSprite = deathsprite;
	m_spawnPosition = spawnlocation;

	m_soundManager = soundmanager;
	m_soundManager->LoadSound("trashcan_death_1.wav", "binDeath");
	m_soundManager->LoadSound("main_attack_trashcan.wav", "binHit");

	m_spawning = false;
	m_spawnTimer = 3.0;
}

SpawnerRubbishBin::~SpawnerRubbishBin()
{

}

RubbishBin* SpawnerRubbishBin::Spawn()
{
	return new RubbishBin(m_sprite, m_deathSprite, m_spawnPosition, m_soundManager);
}


void SpawnerRubbishBin::Update(float &deltatime)
{
	m_spawning = false;
	m_spawnTimer -= deltatime;

	if(m_spawnTimer <= 0.0)
	{
		m_spawning = true;
		m_spawnTimer = 4.0f;
	}
}

bool SpawnerRubbishBin::GetSpawnState()
{
	return m_spawning;
}
