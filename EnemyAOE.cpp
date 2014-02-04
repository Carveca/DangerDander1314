//EnemyAOE.cpp

#include "EnemyAOE.h"

EnemyAOE::EnemyAOE()
{

}

EnemyAOE::~EnemyAOE()
{
	m_collisions.clear();
}

void EnemyAOE::AOEAttack()
{

}

void EnemyAOE::Update()
{


	HandleCollision();
}

void EnemyAOE::HandleCollision()
{
	for(int i = 0; i < m_collisions.size(); i++)
	{

	}

	m_collisions.clear();
}