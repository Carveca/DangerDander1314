//Collider header file

#pragma once
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

	float GetRadius();
	void SetRadius(float value);
	

protected:
	sf::Vector2f m_position;
	sf::Vector2f m_extension;

	float m_radius;
};