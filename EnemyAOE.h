//EnemyAOE.h

#pragma once

#include "Enemy.h"
#include "AOEattack.h"
/*
class Damage {
public:
	enum EDamageType { POINT, AOE , FIRE, ICE, };

	virtual  ~Damage() {};

	EDamageType getType() const { return m_damage_type; };
	int GetAmount(const sf::Vector2f &position) {
		sf::Vector2f dist = m_position - position;

	};

private:
	sf::Vector2f m_position;
	int m_amount;
	EDamageType m_damage_type;
};
*/


class EnemyAOE : public Enemy
{
public:
	EnemyAOE(sf::Sprite sprite, sf::Vector2f position);
	~EnemyAOE();

	void Attack();
	void Update(float elapsedTime);
	void HandleCollision();

	AOEattack* GetAttack();

	/*
	void TakeDamage(Damage* dmg);
	Damage* GiveDamage();
	*/

protected:
	int m_yDirection;

	AOEattack* m_attack;
};