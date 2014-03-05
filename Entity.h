//Entity header file

#pragma once
#include <string>

class SoundManager;

class Entity
{
public:
	Entity();
	Entity(sf::Sprite* sprite, sf::Vector2f &position);
	~Entity();

	virtual void Initialize();
	virtual void Cleanup();	
	virtual void Update(float &deltatime);

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f &position);

	virtual std::string GetName();
	virtual void SetName(std::string &name);

	virtual sf::Sprite* GetSprite();

	virtual sf::Vector2f GetExtension();

protected:
	std::string m_name;
	sf::Sprite* m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_extension;

	float m_frameCounter;
	int m_imageNR;
};