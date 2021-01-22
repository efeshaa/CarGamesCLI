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

	std::string vehicleSelection[3] = { "McLaren 765lt", "Mercedes-AMG GT Black Series", "Honda CIVIC Type-R" };
	bool vehicleSelected = false;
	int selectedVehicle;

	while (true)
	{
		

		// If vehicle isn't selected you prompted to select the vehicle first
		while (!vehicleSelected)
		{
			std::cout << "Vehicle selection:\n" << vehicleSelection[0] << std::endl << vehicleSelection[1] << std::endl << vehicleSelection[2] << "\nSelect (1/2/3): " ;
			std::cin >> selectedVehicle;
			vehicleSelected = true;
			selectedVehicle--;
		}

		// continue with the cli after the vehicle selected
		if (vehicleSelected)
		{
			std::cout << std::endl << "command: ";
			std::cin >> commands;

			// show command from the user
			if (commands == "help")
			{
				std::cout << "Command list:\n1. start\t-> start the car\n2. stop\t\t-> stop the car\n3. status\t-> see car status (on or off)\n4. exit\t\t-> exit the console\n5. lap\t\t-> do lap on track\nThis cli is still on developemnt";
			}
			
			//-------------------------------------- START --------------------------------------
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

			//-------------------------------------- STOP --------------------------------------
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

			//-------------------------------------- EXIT THE TERMINAL --------------------------------------
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

			//-------------------------------------- SHOW VEHICLE STATUS --------------------------------------
			else if (commands == "status")
			{
				std::cout << vehicleSelection[selectedVehicle] << std::endl;
				if (carStatus)
				{
					std::cout << "Car turned on";
				}
				else
				{
					std::cout << "Car turned off";
				}
			}

			//-------------------------------------- DO SOME LAP --------------------------------------
			else if (commands == "lap")
			{
				if (carStatus)
				{
					int lap;
					std::cout << "How many lap you want to do?(1 lap = 30 second): ";
					std::cin >> lap;

					for (int i = 1; i <= lap; i++) {
						if (selectedVehicle = 0)
						{
							std::cout << "Lap " << i << std::endl;
							int lapTime = rand() % 5000 + 20000;
							Sleep(lapTime);
							std::cout << "Lap time: " << lapTime << " Milliseconds" << std::endl;
						}
						else if (selectedVehicle = 1)
						{
							std::cout << "Lap " << i << std::endl;
							int lapTime = rand() % 4000 + 19000;
							Sleep(lapTime);
							std::cout << "Lap time: " << lapTime << " Milliseconds" << std::endl;
						}
						else if (selectedVehicle = 2)
						{
							std::cout << "Lap " << i << std::endl;
							int lapTime = rand() % 6000 + 25000;
							Sleep(lapTime);
							std::cout << "Lap time: " << lapTime << " Milliseconds" << std::endl;
						}
					}
				}
				else {
					std::cout << "You must start your car!";
				}
			}

			//-------------------------------------- CHANGE THE CAR --------------------------------------
			else if (commands == "change")
			{
				if (!carStatus)
				{
					std::cout << "Vehicle selection:\n" << vehicleSelection[0] << std::endl << vehicleSelection[1] << std::endl << vehicleSelection[2] << "\nSelect (1/2/3): ";
					std::cin >> selectedVehicle;
					vehicleSelected = true;
					selectedVehicle--;
				} 
				else
				{
					std::cout << "Turn off the car first";
				}
			}

			//-------------------------------------- SHOW ERROR --------------------------------------
			else
			{
				std::cout << commands << ": command not found use help to get help";
			}
		}
	}
	return 0;
}