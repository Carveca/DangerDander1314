//Level Header File

#pragma once

#include "Entity.h"

class SpriteManager;

class Level : public Entity
{
public:
	Level();
	Level(SpriteManager* spritemanager);
	~Level();

	void Update(float &deltatime);
	void Draw(sf::RenderWindow* window);

	sf::Sprite* GetSprite2();
	sf::Sprite* GetSprite3();
	sf::Sprite* GetSprite4();
	sf::Sprite* GetSprite5();
	sf::Sprite* GetSprite6();

	sf::Sprite* GetTopStreet();
	sf::Sprite* GetBottomStreet();

private:
	SpriteManager* m_spriteManager;

	sf::Sprite* m_sprite2;
	sf::Vector2f m_position2;
	sf::Sprite* m_sprite3;
	sf::Vector2f m_position3;
	sf::Sprite* m_sprite4;
	sf::Vector2f m_position4;
	sf::Sprite* m_sprite5;
	sf::Vector2f m_position5;
	sf::Sprite* m_sprite6;
	sf::Vector2f m_position6;

	/*
	sf::Sprite* m_streetTopSprite;
	sf::Sprite* m_streetBottomSprite;
	sf::Sprite* m_parkSprite;
	sf::Sprite* m_hospitalSprite;
	sf::Sprite* m_buildingSprite;
	sf::Sprite* m_building2Sprite;
	sf::Sprite* m_building3Sprite;
	sf::Sprite* m_building4Sprite;
	sf::Sprite* m_alleySprite;

	sf::Vector2f m_streetTopStart;
	sf::Vector2f m_streetBottomStart;
	sf::Vector2f m_leftImageStart;
	sf::Vector2f m_rightImageStart;
	sf::Vector2f m_leftInitialImageStart;
	sf::Vector2f m_rightInitialImageStart;
	*/
};