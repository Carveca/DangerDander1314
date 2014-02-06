//Engine header

#pragma once

class Player;
class SpriteManager;

class Engine
{
public:
	Engine();
	~Engine();

	bool Initialize();
	void Cleanup();
	void Run();

protected:
	SpriteManager* m_sprite_manager;
	Player* m_player;
		
	sf::RenderWindow m_window;
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	sf::Clock m_clock;
	sf::Vector2f m_direction;

	float m_elapsed_time;

};