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
	void DeathAnimation(float &deltatime);
	

private:
	SoundManager* m_soundManager;

	sf::Sprite* m_deathSprite;

	//int m_deathImageNR;
	//float m_deathTimer;

};
