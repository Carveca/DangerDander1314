//Engine header

#pragma once

class Player;
class PlayerAttack;
class PumpMeter;
class EnemyMelee;
class EnemyAOE;
class Level;

//#include "Level.h"

class SpriteManager;
class CollisionManager;

class Entity;
class InteractiveObject;

class Engine
{
public:
	Engine();
	~Engine();

	bool Initialize();
	void Cleanup();
	void Run();
	void Draw();

protected:
	CollisionManager* m_collisionManager;
	SpriteManager* m_sprite_manager;

	Player* m_player;
	PlayerAttack* m_playerAttack;
	PumpMeter* m_pumpMeter;

	EnemyMelee* m_enemy;
	EnemyMelee* m_enemy2;

	Level* m_level_bottom;
	Level* m_level_top;
		
	sf::RenderWindow m_window;
	sf::Texture PlayerTexture, EnemyMeleeTexture, EnemyAoeTexture, LevelTexture, AttackTexture, PumpTexture;
	sf::Sprite PlayerSprite, EnemyMeleeSprite, EnemyAoeSprite, LevelSprite, AttackSprite, PumpSprite;
	sf::Vector2f m_direction;

	float m_elapsedTime;
	float m_angle;

	std::vector<PlayerAttack*> m_attackContainer;
	std::vector<InteractiveObject*> m_objectContainer;
};