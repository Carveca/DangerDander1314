// Aggressive Bystander Alpha Refactor.cpp : Defines the entry point for the console application.
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

	

	/*
	// temporary game over 
	std::cout << "Game Over" << std::endl;

	sf::Time time = sf::milliseconds(500);
	sf::sleep(time);

	std::cin.clear();

	system("pause");

	// temporary game over 
	*/

	return 0;
}

