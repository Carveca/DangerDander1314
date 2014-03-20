//Spawner Bullet heade file

#pragma once

class Bullet;
class SoundManager;
class SpriteManager;

class SpawnerBullet
{
public:
	//SpawnerBullet();
	SpawnerBullet(SpriteManager* spritemanager, SoundManager* soundmanager);
	~SpawnerBullet();

	Bullet* Spawn(sf::Vector2f &position, sf::Vector2f &direction);
	Bullet* Spawn2(sf::Vector2f &position, sf::Vector2f &direction);


private:
	sf::Sprite* m_bulletSprite;
	sf::Sprite* m_bulletSprite2;

	SoundManager* m_soundManager;
	SpriteManager* m_spriteManager;

	/*
	sf::Vector2f m_bulletPOS;
	sf::Vector2f m_bulletDIR;
	*/

};