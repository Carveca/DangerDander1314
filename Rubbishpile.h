//Rubbishpile.h

#pragma once

#include "InteractiveObject.h"

class Rubbishpile : public InteractiveObject
{
public:
	Rubbishpile(sf::Sprite* sprite, sf::Vector2f &position, SoundManager* soundmanager, float &angle);
	~Rubbishpile();

	void Update(float &deltatime);
	void HandleCollision();

	sf::Sprite* GetAnimation();

private:
	SoundManager* m_soundManager;
	float m_angle;
};