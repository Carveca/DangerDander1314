//Enemy source file
#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	m_points = 1;
}

Enemy::~Enemy()
{

}

void Enemy::AI()
{

}

int Enemy::GetPoints()
{
	return m_points;
}

int Enemy::GetAttackPower()
{
	return m_attack_power;
}