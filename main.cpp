//main.cpp

#include "Player.h"
#include <iostream>
#include <string>

int main()
{
	Player player;

	std::string name = "LOL";

	player.SetName(name);

	std::cout << player.GetName() << std::endl;

	std::cout << player.GetPosition().y << std::endl;

	player.MoveUp();

	std::cout << player.GetPosition().y << std::endl;
	
	system("pause");

	return 0;
}
