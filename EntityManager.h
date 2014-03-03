//Entity Manager header file

#pragma once

class CollisionManager;

class Player;
class PlayerAttack;
class EnemyAOE;

class EntityManager
{
public:
	EntityManager(sf::Sprite* playerSprite, sf::Vector2f playerPOS, sf::Sprite* playerAttackSprite, sf::Sprite* powSprite);
	~EntityManager();

	void Update(float &angle, sf::Vector2f &direction, float &deltatime);	
	void Draw(sf::RenderWindow* window);

public:
	Player* m_player;
	sf::Sprite* m_powSprite;

	void AddEnemyAOE(EnemyAOE* enemyAOE);

private:
	void UpdatePlayer(float &angle, sf::Vector2f &direction,float &deltatime);
	void DrawPlayer(sf::RenderWindow* window);

	void CollisionCheck();
	void CheckHP();	//might be redundant

	void UpdateEnemyAOE(float &deltatime);
	void DrawEnemyAOE(sf::RenderWindow* window);

private:
	CollisionManager* m_collisionManager;

	std::vector<PlayerAttack*> m_playerAttack;
	std::vector<EnemyAOE*> m_enemyAOE;	
};