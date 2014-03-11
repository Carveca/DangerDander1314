//Spawner Bullet source file

#include "stdafx.h"
#include "SpawnerBullet.h"

#include "Bullet.h"
#include "SoundManager.h"

SpawnerBullet::SpawnerBullet(sf::Sprite* bulletsprite, SoundManager* soundmanager)
{
	m_bulletSprite = bulletsprite;
	m_soundManager = soundmanager;
}

SpawnerBullet::~SpawnerBullet()
{

}

Bullet* SpawnerBullet::Spawn(sf::Vector2f &position, sf::Vector2f &direction)
{
	return new Bullet(m_bulletSprite, position, direction, m_soundManager);
}