// Prog II SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "Player.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	/*
	sf::RenderWindow window( sf::VideoMode(1920, 1080), "test");
	sf::Texture texture;
	texture.loadFromFile("main_spritesheet.png", sf::IntRect(0, 0, 139, 97));
	sf::Sprite sprite;
	sprite.setTexture(texture);

	Player player(sprite);

	  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
		window.draw(player.GetSprite());
        window.display();
    }
	 */

	
	Engine engine;

	if(engine.Initialize())
	{
		engine.Run();
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