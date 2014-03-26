//Engine header

/*
#pragma once

class Player;
class PlayerAttack;
class PumpMeter;
class EnemyMelee;
class EnemyAOE;
class Level;
class SpriteManager;
class CollisionManager;
class SpawnerAOEenemy;
class Entity;
class InteractiveObject;
*/

#pragma once

class StateManagerII;

class Engine
{

public:
	Engine();
	~Engine();

	bool Initialize();

	void Run();


private:
	StateManagerII* m_stateManager;	

	sf::Clock* m_clock;

};










/*
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

	SpawnerAOEenemy* m_spawner_AOEenemy;
		
	sf::RenderWindow m_window;
	sf::Texture PlayerTexture, PlayerAttackTexture, EnemyMeleeTexture, EnemyAoeTexture, LevelTexture, AttackTexture, PumpTexture, AOEtexture;
	sf::Sprite PlayerSprite, PlayerAttackSprite, EnemyMeleeSprite, EnemyAoeSprite, LevelSprite, AttackSprite, PumpSprite, AOEsprite;
	sf::Vector2f m_direction;

	float m_elapsedTime;
	float m_angle;

	std::vector<PlayerAttack*> m_attackContainer;
	std::vector<EnemyAOE*> m_AOEenemyContainer;
};
*/