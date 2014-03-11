//Collider source file
#include "stdafx.h"
#include "Collider.h"
#include "InteractiveObject.h"

Collider::Collider()
{
	
}

Collider::~Collider()
{

}

//Overlap methods

bool Collider::OverlapBoxVsBox(InteractiveObject* other, sf::Vector2f &offset)
{
	sf::Vector2f off;

	/*
	float distance_X			= fabs( m_position.x - other->GetCollider()->GetPosition().x);
	float control_distance_X	= (m_extension.x * 0.5f) + (other->GetCollider()->GetExtension().x * 0.5f);

	float distance_Y			= fabs( m_position.y - other->GetCollider()->GetPosition().y);
	float control_distance_Y	= (m_extension.y * 0.5f) + (other->GetCollider()->GetExtension().y * 0.5f);

	if(distance_X <= control_distance_X)
	{
		if(distance_Y <= control_distance_Y)
		{
			float delta_X = distance_X / (m_extension.x + other->GetCollider()->GetExtension().x);
			float delta_Y = distance_Y / (m_extension.y + other->GetCollider()->GetExtension().y);

			if(delta_X >= delta_Y)
			{
				if(m_position.x > other->GetCollider()->GetPosition().x)
				{
					off.x = control_distance_X - distance_X;
				}
				else
				{
					off.x = -(control_distance_X - distance_X);
				}
				
			}
			else if(delta_X < delta_Y)
			{
				if(m_position.y > other->GetCollider()->GetPosition().y)
				{
					off.y = control_distance_Y - distance_Y;
				}

				else
				{
					off.y = -(control_distance_Y - distance_Y);
				}

			}

			offset += off;

			return true;	
		}
	}
	*/



	return false;
}

bool Collider::OverlapCircleVsCircle(InteractiveObject* other, sf::Vector2f &offset)
{
	sf::Vector2f off = sf::Vector2f(0.0f, 0.0f);
	
	sf::Vector2f centered_this = m_position;
		centered_this.x += (m_extension.x * 0.5f);
		centered_this.y += (m_extension.y * 0.5f);

	sf::Vector2f centered_other = other->GetCollider()->GetPosition();
		centered_other.x += (other->GetCollider()->GetExtension().x * 0.5);
		centered_other.y += (other->GetCollider()->GetExtension().y * 0.5);

	float distance_X	= ( centered_this.x - centered_other.x );
	float distance_Y	= ( centered_this.y - centered_other.y );
	float distance_REAL = sqrt( pow(distance_X, 2.0f) + pow(distance_Y, 2.0f) );

	float radiuses_sum	= m_radius + other->GetCollider()->GetRadius();

	if(radiuses_sum > distance_REAL)
	{
		off = other->GetCollider()->GetPosition();

		float angle = std::atan2f(distance_Y, distance_X);

		off.x += std::cosf(angle) * (radiuses_sum );
		off.y += std::sinf(angle) * (radiuses_sum );

		offset = off;
		return true;
	}

/*
	if( distance_REAL <= radiuses_sum )
	{
		float delta_X = fabs(radiuses_sum - distance_X);
		float delta_Y = fabs(radiuses_sum - distance_Y);

		if( delta_X < delta_Y)
		{
			if(m_position.x > other->GetCollider()->GetPosition().x)
			{
				off.x = delta_X;
			}
			else
			{
				off.x = -delta_X;
			}
		}

		else if( delta_X > delta_Y)
		{
			if(m_position.y > other->GetCollider()->GetPosition().y)
			{
				off.y = delta_Y;
			}
			else
			{
				off.y = -delta_Y;
			}
		}
		*/
				
	return false;
}

//return and set values

sf::Vector2f Collider::GetPosition()
{
	return m_position;
}

void Collider::SetPosition(sf::Vector2f &position)
{
	m_position.x = position.x;
	m_position.y = position.y;
}

sf::Vector2f Collider::GetExtension()
{
	return m_extension;
}

void Collider::SetExtension(sf::Vector2f &extension)
{
	m_extension = extension;
}
	
float Collider::GetRadius()
{
	return m_radius;
}

void Collider::SetRadius(float value)
{
	m_radius = value;
}