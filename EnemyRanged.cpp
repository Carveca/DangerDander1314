//EnemyRanged.cpp

#include "stdafx.h"
#include "EnemyRanged.h"

EnemyRanged::EnemyRanged()
{

}

EnemyRanged::~EnemyRanged()
{
	m_collisions.clear();
}

void EnemyRanged::RangedAttack()
{

}

void EnemyRanged::Update()
{


	HandleCollision();
}

void EnemyRanged::HandleCollision()
{
	for(int i = 0; i < m_collisions.size(); i++)
	{

	}

	m_collisions.clear();
}