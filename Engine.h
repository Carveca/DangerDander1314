//Engine header

#pragma once

class Player;
class PlayerAttack;
class PumpMeter;
class EnemyMelee;

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
	
	PlayerAttack* m_attack;

		
	sf::RenderWindow m_window;
	sf::Texture PlayerTexture, EnemyMeleeTexture, LevelTexture, AttackTexture, PumpTexture;
	sf::Sprite PlayerSprite, EnemyMeleeSprite, LevelSprite, AttackSprite, PumpSprite;
	sf::Clock m_clock;
	sf::Vector2f m_direction;

	float m_elapsedTime;
	float m_angle;


	std::vector<PlayerAttack*> m_attackContainer;
	std::vector<InteractiveObject*> m_objectContainer;
};