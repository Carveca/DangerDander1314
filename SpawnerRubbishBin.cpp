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
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_sprite = sprite;
	m_deathSprite = deathsprite;
	m_spawnPosition = spawnlocation;

	m_soundManager = soundmanager;
	m_soundManager->LoadSound("trashcan_death_1.wav", "binDeath");
	m_soundManager->LoadSound("main_attack_trashcan.wav", "binHit");

	m_spawning = false;
	m_spawnTimer = m_reader->m_settings["BinSpawnerInitialTimer"];
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
		m_spawnTimer = m_reader->m_settings["BinSpawnerTimer"];
	}
}

bool SpawnerRubbishBin::GetSpawnState()
{
	return m_spawning;
}
