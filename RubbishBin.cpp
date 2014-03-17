//Rubbis Bin source file

#include "stdafx.h"
#include "RubbishBin.h"
#include "Collider.h"
#include "SoundManager.h"

RubbishBin::RubbishBin(sf::Sprite* binSprite, sf::Sprite* binDeathSprite, sf::Vector2f &position, SoundManager* soundmanager)
{
	m_reader = new FileReader;
	m_reader->Initialize("../Data/");
	m_reader->LoadFile("settings.txt");

	m_hp = 1;
	m_speed = 100;
	m_angle = 0;
	m_name = "RubbishBin";

	m_position = position;
	m_extension = sf::Vector2f(128, 128);

	m_soundManager = soundmanager;

	m_sprite = binSprite;
	m_sprite->setPosition(GetPosition());
	m_sprite->setOrigin(64, 64);

	m_deathSprite = binDeathSprite;
	m_sprite->setPosition(GetPosition());
	m_sprite->setOrigin(64, 64);

	m_spawnedTrash = false;
	m_knockedOver = false;
	m_knockedOverSound = false;
	m_hitSound = false;
	m_dead = false;
	m_imageNR = 0;
	m_frameCounter = 0.0f;

	m_collider = new Collider;
	m_collider->SetPosition(GetPosition());
	m_collider->SetExtension(GetExtension());
	m_collider->SetRadius(60);
	m_colliderCircle = true;
	
}

RubbishBin::~RubbishBin()
{

}

void RubbishBin::Update(float &deltatime)
{
	m_position.y += m_speed * deltatime;
	
	m_collider->SetPosition(GetPosition());

	HandleCollision();

}



std::pair<sf::IntRect, int> RubbishBin::DeathAnimation(float &deltatime, float &playerangle) 
{
	if(!m_knockedOverSound)
	{
		m_soundManager->PlaySound("binDeath");
		m_knockedOverSound = true;
	}

	//animation
	
	m_frameCounter += deltatime;
	if(m_frameCounter >= 0.1f)
	{
		m_imageNR++;
		m_frameCounter = 0.0f;
		if(m_imageNR > 4)
			m_imageNR = 5;
	}

	std::pair<sf::IntRect, int> animationPair;
	animationPair = std::make_pair (sf::IntRect( 128 * m_imageNR, 0, 128, 128), playerangle);

	return animationPair;
}

void RubbishBin::HandleCollision()
{
	for(int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "TrashBin")
		{

		}
		if(m_collisions[i].first->GetName() == "PlayerAttack")
		{
			if(!m_hitSound)
			{
				m_soundManager->PlaySound("binHit");
				m_hitSound = true;
			}
			m_hp -= 1;
		}
	}

	m_collisions.clear();
}

sf::Vector2f RubbishBin::RubbishSpawn(float angle)
{	
	sf::Vector2f rubbishSpawn(GetPosition());
	
	if(angle == 0)
		rubbishSpawn += sf::Vector2f(0, -100);
	else if(angle == 45)
		rubbishSpawn += sf::Vector2f(100, -100);
	else if(angle == 90)
		rubbishSpawn += sf::Vector2f(100, 0);
	else if(angle == 135)
		rubbishSpawn += sf::Vector2f(100, 100);
	else if(angle == 180)
		rubbishSpawn += sf::Vector2f(0, 100);
	else if(angle == 225)
		rubbishSpawn += sf::Vector2f(-100, 100);
	else if(angle == 270)
		rubbishSpawn += sf::Vector2f(-100, 0);
	else if(angle == 315)
		rubbishSpawn += sf::Vector2f(-100, -100);

	//Vector2f(cos(v) * 100, sin(v) * 100)

	return rubbishSpawn;
}

sf::Sprite* RubbishBin::GetDeathSprite(float &deltatime, float &playerangle)
{	
	std::pair<sf::IntRect, int> animationpair(DeathAnimation(deltatime, playerangle));

	m_deathSprite->setPosition(GetPosition());
	m_deathSprite->setOrigin(64, 64);

	m_deathSprite->setTextureRect(animationpair.first);

	if(!m_knockedOver)
	{
		m_angle = animationpair.second;
		m_knockedOver = true;
	}

	m_deathSprite->setRotation(m_angle);

	return m_deathSprite;
}