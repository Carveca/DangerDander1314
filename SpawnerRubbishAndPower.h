//Rubbish and PowerUp Spawner header file

#pragma once

class BlueCow;
class HappyPill;
class Rubbishpile;

class SoundManager;

class SpawnerRubbishAndPower
{
public:
	SpawnerRubbishAndPower(sf::Sprite* spritebluecow, sf::Sprite* spritehappypill, sf::Sprite* spriterubbish, SoundManager* soundmanager);
	~SpawnerRubbishAndPower();

	BlueCow* SpawnBlueCow();
	HappyPill* SpawnHappyPill();
	Rubbishpile* SpawnRubbish();

	void Update();
	void SetSpawnPOS(sf::Vector2f &spawnlocation);

	bool GetSpawnState();

protected:	
	bool m_spawning;

	sf::Vector2f m_spawnPosition;

	sf::Sprite* m_spriteBlueCow;
	sf::Sprite* m_spriteHappyPill;
	sf::Sprite* m_spriteRubbish;

	SoundManager* m_soundManager;
};