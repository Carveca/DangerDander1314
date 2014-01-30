//main.cpp

#include "Player.h"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{

	sf::Window GameWindow;
	GameWindow.create(sf::VideoMode(1920, 1080), "Dangerous Dander");

	while(GameWindow.isOpen())
	{
		sf::Event event;

		while(GameWindow.pollEvent(event))
		{

			if(event.type == sf::Event::Closed)
			{
				GameWindow.close(); 
			}

		}


	}

	/*
	Player player;

	std::string name = "Lolol";

	player.SetName(name);

	std::cout << player.GetName() << std::endl;

	std::cout << player.GetPosition().y << std::endl;

	player.MoveUp();

	std::cout << player.GetPosition().y << std::endl;
	*/

	system("pause");

	return 0;
}