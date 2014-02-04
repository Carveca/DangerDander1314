//Player source file
#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_name = "Player";
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
	


	HandleCollision();

}

void Player::HandleCollision()
{
	for(int i = 0; i < m_collisions.size(); i++)
	{





	}
	
	m_collisions.clear();
}