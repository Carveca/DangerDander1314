//Collider header file

#pragma once

#include <SFML/System/Vector2.hpp>

class InteractiveObject;

class Collider
{
public:
	Collider();
	~Collider();

	bool OverlapBoxVsBox(InteractiveObject* other, sf::Vector2f &offset);
	bool OverlapCircleVsCircle(InteractiveObject* other, sf::Vector2f &offset);
			
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f position);

	sf::Vector2f GetExtension();
	void SetExtension(sf::Vector2f extension);
	

protected:
	sf::Vector2f m_position;
	sf::Vector2f m_extension;

};