//Player source file
#include "stdafx.h"
#include "Player.h"
#include "Collider.h"

Player::Player(sf::Sprite sprite) 
{
	m_name = "Player";
	m_collider = new Collider;

	m_sprite = sprite;
	m_speed = 300.0f;
}

Player::~Player()
{

}

void Player::Initialize()
{

}

void Player::Cleanup()
{
	m_collisions.clear();
}

void Player::Update()
{

	m_sprite.setPosition(m_position);

	HandleCollision();

}

void Player::HandleCollision()
{
	for(int i = 0; i < m_collisions.size(); i++)
	{





	}
	
	m_collisions.clear();
}

sf::Sprite Player::GetSprite()
{
	return m_sprite;
}