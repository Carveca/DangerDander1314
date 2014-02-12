//Engine header

#pragma once

class Player;
class SpriteManager;
class EnemyMelee;
class CollisionManager;
class Entity;

class Engine
{
public:
	Engine();
	~Engine();

	bool Initialize();
	void Cleanup();
	void Run();

protected:
	CollisionManager* m_collisionManager;
	SpriteManager* m_sprite_manager;
	Player* m_player;
	EnemyMelee* m_enemy;
	EnemyMelee* m_enemy2;
	
	Entity* m_level;
		
	sf::RenderWindow m_window;
	sf::Texture PlayerTexture, EnemyMeleeTexture, LevelTexture;
	sf::Sprite PlayerSprite, EnemyMeleeSprite, LevelSprite;
	sf::Clock m_clock;
	sf::Vector2f m_direction;

	float m_elapsedTime;
	float m_angle;

};