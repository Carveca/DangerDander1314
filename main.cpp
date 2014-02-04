// Prog II SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(1024, 640), "Caption");
	sf::CircleShape shape(10.0f);
	sf::Sprite sprite;
	
	sf::Vector2u size;
	size.x = 100;
	size.y = 100;

	sf::Vector2u size2;
	size2 = window.getSize();

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

			else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				window.setSize(size);
			}

			else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
			{
				window.setSize(size2);
			}

			window.clear(sf::Color(0x11, 0x22, 0x33, 0xff));
			window.draw(shape);
			window.display();

		}

		


	}



	return 0;
}

/*
	StateManager
	InputManager
	AudioManager
	Collider
	CollisionManager
	EntityManager*
	DrawManager

	*
	BulletManager
	EnemyManager
	...

	SpriteManager
	Sprite


	UML - google

*/