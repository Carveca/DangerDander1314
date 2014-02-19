// Prog II SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "Player.h"

#include <iostream>
#include <time.h>
#include <math.h>

int _tmain(int argc, _TCHAR* argv[])
{	

	srand(time(0));
	
	Engine engine;

	if(engine.Initialize())
	{
		engine.Run();
	}
	
	std::cout << "Game Over" << std::endl;

	sf::Time time = sf::milliseconds(500);
	sf::sleep(time);

	std::cin.clear();

	system("pause");
	
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