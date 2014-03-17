//Player source file
#include "stdafx.h"
#include "Player.h"

#include "Collider.h"
#include "PlayerAttack.h"
#include "SoundManager.h"

#include <iostream>

Player::Player(sf::Sprite* sprite, sf::Vector2f &position, sf::Sprite* attackSprite, SoundManager* soundmanager, sf::Sprite* deathAnimation) 
{
	//FileReader reader;
	reader.Initialize("../Data/");
	reader.LoadFile("settings.txt");

	m_extension.x = 128;
	m_extension.y = 128;
	m_position = position;


	m_name = "Player";
	m_speed = reader.m_settings["PlayerSpeed"];
	m_hp = reader.m_settings["PlayerHPStart"];
	m_hpDrain = reader.m_settings["PlayerHPDrain"];
	m_score = 0;

	m_collider = new Collider;
	m_colliderCircle = true;
	m_collider->SetRadius(reader.m_settings["PlayerRadius"]);
	m_collider->SetExtension(GetExtension());
	m_collider->SetPosition(GetPosition());

	m_soundManager = soundmanager;
	m_soundManager->LoadSound("main_attack_swing.wav", "PlayerAttack");
	m_soundManager->LoadSound("main_movement.wav", "PlayerMove");
	m_soundManager->LoadSound("blue_cow.wav", "BlueCow");
	m_soundManager->LoadSound("bingo_1.wav", "Happy");

	//m_soundManager->LoadSound("aoe_attack.wav", "AOE"); //needs timer or something

	if(sprite != nullptr)
	{
		m_sprite = sprite;
		m_sprite->setOrigin(128, 128);		
	}
	else
	{
		std::cout << "Player Sprite fail" << std::endl;
	}
	m_imageNR = 0;
	m_frameCounter = 0.0f;
	
	//AttackAnimation
	m_attackSprite = attackSprite;
	m_attackSprite->setOrigin(128, 128);
	m_attackSprite->setTextureRect(sf::IntRect(0, 0, 256, 256));
	m_attackImageNR = 0;
	m_attackFrameCounter = 0.0f;

	//DeathAnimation
	m_deathSprite = deathAnimation;
	m_deathSprite->setOrigin(128, 128);
	m_deathImageNR = 0;
	m_deathFrameCounter = 0.0f;

	m_happyPills = 0;
	m_blueCows = 0;
	
	m_moveSoundTimer = 0.0f;
	m_attackTimer = 0.0f;
	m_drainTimer = 0.0f;
	m_blueCowTimer = 0.0f;

	m_weaponSize = reader.m_settings["PlayerWeaponSize"];
	m_isAttacking = false;
	m_attackAnimation = false;
}

Player::~Player()
{
	delete m_collider;
	m_collider = nullptr;

	std::cout << m_score << std::endl;
}

void Player::Initialize()
{

}

void Player::Cleanup()
{
	m_collisions.clear();
}

void Player::Update(float &angle, sf::Vector2f &direction, float &elapsedtime)
{	
	
	if(m_blueCowTimer < 0.0)
	{
		m_speed = reader.m_settings["PlayerSpeed"];
		m_blueCowTimer = 0.0;
	}
	if(m_blueCowTimer > 0.0)
	{
		m_speed = reader.m_settings["PlayerBoostedSpeed"];
	}

	m_blueCowTimer -= elapsedtime;

	//Move
	Move(direction, elapsedtime);
	m_moveSoundTimer += elapsedtime;
	if(m_moveSoundTimer >= 0.4)
	{
		m_moveSoundTimer = 0.0;
		m_soundManager->PlaySound("PlayerMove");
	}

	//m_collider->SetPosition(m_position);
	m_sprite->setPosition(m_position);
	m_attackSprite->setPosition(m_position);
	
	//Attack
	m_isAttacking = false;
	m_attackAnimation = false;

	if(m_attackTimer <= 0.3 && m_attackTimer > 0.0)
	{
		m_attackAnimation = true;

		if(m_attackTimer <= 0.2 && m_attackTimer > 0.0)
			m_isAttacking = true;		
	}	

	m_attackTimer -= elapsedtime;
	if(m_attackTimer < -10)
	{
		m_attackTimer = 0.0f;
	}	

	//Sprite

	if(m_attackAnimation)
	{
		m_attackSprite->setTextureRect(sf::IntRect( 257 * m_attackImageNR, 0, 256, 256));
		m_attackFrameCounter += elapsedtime;
		if(m_attackFrameCounter >= 0.1f)
		{
			m_attackImageNR++;
			m_attackFrameCounter = 0.0f;
			if(m_attackImageNR > 2)
				m_attackImageNR = 0;
		}
		m_attackSprite->setRotation(angle);
	}

	else if(!m_attackAnimation)
	{
		m_sprite->setTextureRect(sf::IntRect( 257 * m_imageNR, 0, 256, 256));
		m_frameCounter += elapsedtime;
		if(m_frameCounter >= 0.1f)
		{
			m_imageNR++;
			m_frameCounter = 0.0f;
			if(m_imageNR > 7)
				m_imageNR = 0;
		}
		m_sprite->setRotation(angle);
	}
		
	//Collision
	HandleCollision();

	//HP
	m_drainTimer += elapsedtime;
	if(m_drainTimer >= 0.1)
	{
		m_hp += m_hpDrain;
		m_drainTimer = 0.0;
		
		m_hpDrain = reader.m_settings["PlayerHPDrain"];
	}

	if(m_hp > 100)
	{
		m_hp = 100;
	}
	else if(m_hp < 0)
	{
		m_hp = 0;
	}

	
	//X-Bounds
	if(m_position.x < 360)
		m_position.x = 360;
	if(m_position.x > 1560)
		m_position.x = 1560;
	//Y-Bounds
	if(m_position.y < 80)
		m_position.y = 80;
	if(m_position.y > 1000)
		m_position.y = 1000;
}

void Player::HandleCollision()
{
	m_collider->SetPosition(GetPosition());

	for(unsigned int i = 0; i < m_collisions.size(); i++)
	{
		if(m_collisions[i].first->GetName() == "Player" || m_collisions[i].first->GetName() == "PlayerAttack")
		{
			
		}
		
		else if(m_collisions[i].first->GetName() == "AOEattack")
		{
			m_hpDrain = 1;
		}

		else if(m_collisions[i].first->GetName() == "HappyPill")
		{
			m_happyPills++;
		}

		else if(m_collisions[i].first->GetName() == "BlueCow")
		{
			m_blueCows++;
		}
		else if(m_collisions[i].first->GetName() == "MeleeAttack")
		{
			
		}
		else 
		{
			m_position = m_collisions[i].second;
		}

	}
	
	m_collisions.clear();
}

sf::Sprite* Player::GetSprite()
{
	return m_sprite;
}

void Player::Attack()
{
	if(m_attackTimer <= 0)
	{
		m_soundManager->PlaySound("PlayerAttack");
		m_attackTimer = 0.3;
	}
}

float Player::GetAttackTimer()
{
	return m_attackTimer;
}

void Player::WeaponStick()
{
	m_weaponSize = 120;
}

bool Player::GetAttacking()
{
	return m_isAttacking;
}

int Player::GetWeaponSize()
{
	return m_weaponSize;
}

void Player::ChangeHP(int value)
{
	m_hp += value;

	if(m_hp > 100)
		m_hp = 100;
	else if(m_hp < 0)
		m_hp = 0;
}

void Player::SetAttackAnimationStop()
{
	m_attackAnimation = false;
	m_attackFrameCounter = 0.0;
	m_attackImageNR = 0;
}

bool Player::GetAttackAnimation()
{
	return m_attackAnimation;
}

sf::Sprite* Player::GetAttackSprite()
{
	return m_attackSprite;
}

void Player::UseHappyPill()
{
	if (m_happyPills > 0)
	{
		m_soundManager->PlaySound("Happy");
		m_happyPills--;
		ChangeHP(reader.m_settings["PlayerHappyEffect"]);
	}
}

void Player::UseBlueCow()
{
	if (m_blueCows > 0)
	{
		m_soundManager->PlaySound("BlueCow");
		m_blueCows--;
		m_blueCowTimer = reader.m_settings["PlayerBoostedSpeedDuration"];		
	}
}

void Player::AddScore(int value)
{
	m_score += value;
}

int Player::GetScore()
{
	return m_score;
}