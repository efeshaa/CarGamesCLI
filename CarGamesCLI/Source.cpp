#include<iostream>
#include<string>
#include<Windows.h>

/*
* This is a simple car games with cli (command line interface)
* command list:
*	1. start	-> start the car
*	2. stop		-> stop the car
*	3. status	-> see the car status (on or off)
*	4. exit		-> exit the games
*	5. lap		-> do lap on track
*/

int main()
{
	bool carStatus = false;
	std::string commands;

	std::cout << "Welcome to simple car games (still on development)";

	while (true)
	{
		std::cout << std::endl << "command: ";
		std::cin >> commands;

		if (commands == "help")
		{
			std::cout << "Command list:\n1. start\t-> start the car\n2. stop\t\t-> stop the car\n3. status\t-> see car status (on or off)\n4. exit\t\t-> exit the console\n5. lap\t\t-> do lap on track\nThis cli is still on developemnt";
		}
		else if (commands == "start")
		{
			if (!carStatus)
			{
				carStatus = true;
				std::cout << "Car started";
			}
			else if (carStatus)
			{
				std::cout << "Car already started use stop to stop the car";
			}
		}
		else if (commands == "stop")
		{
			if (!carStatus)
			{
				std::cout << "Car already stopped use start to start the car";
			}
			else if (carStatus)
			{
				carStatus = false;
				std::cout << "Car stopped";
			}
		}
		else if (commands == "exit")
		{
			if (carStatus)
			{
				std::cout << "You must turn off your car...";
			}
			else
			{
				return 0;
			}
		}
		else if (commands == "status")
		{
			if (carStatus)
			{
				std::cout << "Car turned on";
			}
			else
			{
				std::cout << "Car turned off";
			}
		}
		else if (commands == "lap")
		{
			if (carStatus)
			{
				int lap;
				std::cout << "How many lap you want to do?(1 lap = 30 second): ";
				std::cin >> lap;

				for (int i = 1; i <= lap; i++) {
					std::cout << "Lap " << i << std::endl;
					int lapTime = rand() % 5000 + 20000;
					Sleep(lapTime);
					std::cout << "Lap time: " << lapTime << " Milliseconds" << std::endl;
				}
			}
			else {
				std::cout << "You must start your car!";
			}
		}
		else
		{
			std::cout << commands << ": command not found use help to get help";
		}
	}
	return 0;
}