//Entity header file

#pragma once

#include <string>

#include <SFML/System/Vector2.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	void Initialize();
	void Cleanup();	
	void Update();

	sf::Vector2f GetPosition();
	void SetPosition();

	std::string GetName();
	void SetName(std::string name);

protected:
	std::string m_name;

	sf::Vector2f m_position;

};