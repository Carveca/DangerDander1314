//Spawner Bullet heade file

#pragma once

class Bullet;
class SoundManager;

class SpawnerBullet
{
public:
	//SpawnerBullet();
	SpawnerBullet(sf::Sprite* bulletsprite, SoundManager* soundmanager);
	~SpawnerBullet();

	Bullet* Spawn(sf::Vector2f &position, sf::Vector2f &direction);


private:
	sf::Sprite* m_bulletSprite;

	SoundManager* m_soundManager;

	/*
	sf::Vector2f m_bulletPOS;
	sf::Vector2f m_bulletDIR;
	*/

};