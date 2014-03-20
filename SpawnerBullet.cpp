//Spawner Bullet source file

#include "stdafx.h"
#include "SpawnerBullet.h"

#include "Bullet.h"
#include "SoundManager.h"
#include "SpriteManager.h"

SpawnerBullet::SpawnerBullet(SpriteManager* spritemanager, SoundManager* soundmanager)
{
	m_spriteManager = spritemanager;

	m_bulletSprite = m_spriteManager->GetSprite("bullet.png", 16, 16);
	m_bulletSprite2 = m_spriteManager->GetSprite("rock.png", 20, 20);

	m_soundManager = soundmanager;
}

SpawnerBullet::~SpawnerBullet()
{

}

Bullet* SpawnerBullet::Spawn(sf::Vector2f &position, sf::Vector2f &direction)
{
	return new Bullet(m_bulletSprite, position, direction, m_soundManager);
}

Bullet* SpawnerBullet::Spawn2(sf::Vector2f &position, sf::Vector2f &direction)
{
	return new Bullet(m_bulletSprite2, position, direction, m_soundManager);
}