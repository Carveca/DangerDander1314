// Aggressive Bystander Alpha Refactor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "Player.h"
#include "FileReader.h"

#include <iostream>
#include <time.h>
#include <math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*
	//global?
	FileReader reader;	
	reader.Initialize("../Data/");
	reader.LoadFile("settings.txt");
		
	std::cout << reader.m_settings["ScreenWidth"] << std::endl;
	std::cout << reader.m_settings["ScreenHeight"] << std::endl;
	*/

	
	srand(time(0));	
	Engine engine;

	if(engine.Initialize())
	{
		engine.Run();
	}

	//system("pause");

	return 0;
}

