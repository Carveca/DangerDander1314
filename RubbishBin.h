//Rubbish Bin Header

#pragma once

#include "Enemy.h"

class SoundManager;

class RubbishBin : public Enemy
{
public:
	RubbishBin(sf::Sprite* binSprite, sf::Sprite* binDeathSprite, sf::Vector2f &position, SoundManager* soundmanager);
	~RubbishBin();

	void Update(float &deltatime);
	void HandleCollision();

	std::pair<sf::IntRect, int> DeathAnimation(float &deltatime, float &playerangle);
	
	sf::Sprite* GetDeathSprite(float &deltatime, float &playerangle);

	sf::Vector2f RubbishSpawn(float angle);

private:
	SoundManager* m_soundManager;
	FileReader* m_reader;

	sf::Sprite* m_deathSprite;

	int m_angle;

public:
	bool m_dead;
	bool m_knockedOver;
	bool m_spawnedTrash;

	bool m_hitSound;
	bool m_knockedOverSound;
};
