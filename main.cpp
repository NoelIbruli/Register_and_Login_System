/* Register and Login system created by Noel Ibruli using C++ (2021)
 *
 * The program prompts the user to enter a number between 0-2
 * 
 * 0 => exits the program
 * 1 => Prompts the user to enter their credentials which will later be appended in a file
 * 3 => Prompts the user to enter their username and password and if they are found login is successful
 */

#include "helperFunctions.h"
#include "info.h"
#include "login.h"
#include <iostream>
#include <fstream>

int main(void)
{	
	std::fstream infofile; // creates a varibale file
	std::fstream loginfile; // create a variable for the other file

	struct PersonalInfo personal; // struct instantiation

	int input; // variable will take input from user
	
	do
	{
		welcome(); // call welcome() function
		std::cin >> input; // receive input
		clearBuffer(); // clears the buffer

	}while (input > 2 || input < 0);

	while (input)
	{
		if (input == 1)
		{	
		
			reg(personal, infofile, loginfile); // call reg() function
			system("clear"); // function to clear the screen
                       	welcome(); // call welcome() function
                       	std::cin >> input; // receive input
		}		
		else if (input == 2)
		{
			clearBuffer(); // clears the buffer
			log(personal, loginfile); // login function
                       	welcome(); // call welcome() function
                       	std::cin >> input; // receive input
		}
		else if (input == 0)
		{
				std::cout << "Bye\n";
		}
		
	}	
	return 0;
}
