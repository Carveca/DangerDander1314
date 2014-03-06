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

	return 0;
}

