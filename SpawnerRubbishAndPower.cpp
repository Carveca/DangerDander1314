//Spawner Rubbish and PowerUp source file

#include "stdafx.h"
#include "SpawnerRubbishAndPower.h"

#include "BlueCow.h"
#include "HappyPill.h"
#include "Rubbishpile.h"
#include "SoundManager.h"

SpawnerRubbishAndPower::SpawnerRubbishAndPower(sf::Sprite* spritebluecow, sf::Sprite* spritehappypill, sf::Sprite* spriterubbish, SoundManager* soundmanager)
{
	m_spawning = false;

	m_spawnPosition = sf::Vector2f(0, 0);
	
	m_spriteBlueCow = spritebluecow;
	m_spriteHappyPill = spritehappypill;
	m_spriteRubbish = spriterubbish;

	m_soundManager = soundmanager;

}

SpawnerRubbishAndPower::~SpawnerRubbishAndPower()
{

}

void SpawnerRubbishAndPower::Update()
{
	m_spawning = false;
}

bool SpawnerRubbishAndPower::GetSpawnState()
{
	return m_spawning;
}

BlueCow* SpawnerRubbishAndPower::SpawnBlueCow()
{
	return new BlueCow(m_spriteBlueCow, m_spawnPosition);
}

HappyPill* SpawnerRubbishAndPower::SpawnHappyPill()
{
	return new HappyPill(m_spriteHappyPill, m_spawnPosition);
}

Rubbishpile* SpawnerRubbishAndPower::SpawnRubbish(float &angle)
{
	return new Rubbishpile(m_spriteRubbish, m_spawnPosition, m_soundManager, angle);
}

void SpawnerRubbishAndPower::SetSpawnPOS(sf::Vector2f &spawnlocation)
{
	m_spawnPosition = spawnlocation;
}