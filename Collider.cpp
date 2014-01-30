//Collider source file

#include "Collider.h"
#include "InteractiveObject.h"

Collider::Collider()
{
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_extension.x = 1.0f;
	m_extension.y = 1.0f;

}

Collider::~Collider()
{

}

//Overlap methods

bool Collider::OverlapBoxVsBox(InteractiveObject* other)
{
	float distance_X			= fabs( m_position.x - other->GetCollider()->GetPosition().x);
	float control_distance_X	= (m_extension.x * 0.5f) + (other->GetCollider()->GetExtension().x * 0.5f);

	float distance_Y			= fabs( m_position.y - other->GetCollider()->GetPosition().y);
	float control_distance_Y	= (m_extension.y * 0.5f) + (other->GetCollider()->GetExtension().y * 0.5f);

	if(distance_X <= control_distance_X)
	{
		if(distance_Y <= control_distance_Y)
		{
			return true;	
		}
	}
	
	return false;
}

bool Collider::OverlapCircleVsCircle(InteractiveObject* other)
{
	sf::Vector2f centered_this = m_position;
	centered_this.x += (m_extension.x * 0.5f);
	centered_this.y += (m_extension.y * 0.5f);

	sf::Vector2f centered_other = other->GetCollider()->GetPosition();
	centered_other.x += (other->GetCollider()->GetExtension().x * 0.5);
	centered_other.y += (other->GetCollider()->GetExtension().y * 0.5);

	float distance_X	= fabs( centered_this.x - centered_other.x );
	float distance_Y	= fabs( centered_this.y - centered_other.y );
	float distance_REAL = sqrt( pow(distance_X, 2.0f) + pow(distance_Y, 2.0f) );

	float radiuses_sum	= (m_extension.x * 0.5f) + (other->GetCollider()->GetExtension().x * 0.5f);

	if( distance_REAL <= radiuses_sum )
	{
		return true;		
	}

	return false;
}

//return and set values

sf::Vector2f Collider::GetPosition()
{
	return m_position;
}

void Collider::SetPosition(sf::Vector2f position)
{
	m_position.x = position.x;
	m_position.y = position.y;
}

sf::Vector2f Collider::GetExtension()
{
	return m_extension;
}

void Collider::SetExtension(sf::Vector2f extension)
{
	m_extension = extension;
}
	