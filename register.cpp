#include "helperFunctions.h"
#include "info.h"
#include <iostream>
#include <fstream>

int checkUsernamePass(struct PersonalInfo personal)
{

	// checks if a string contains a substring
	size_t found = personal.m_login.m_username.find(personal.m_login.m_password);
	if (found != std::string::npos)
		return 1; // return 1 if they match
	else 
		return 0; // return 0 if they don't match
}

//function to check if re-entered password is correct
int checkPassword(struct PersonalInfo personal)
{
        if (personal.m_login.m_password == personal.m_login.m_check_pass)
                return 0; // if passwords match return 0
        else
                return 1; // if passwords don't match return 1
}     

// function to write input for the user info into a .txt file
void reg(struct PersonalInfo personal, std::fstream& infofile, std::fstream& loginfile)
{
	int returnVal_Pass = 0; // will store the return value of checkPassword()
	int returnVal_Name = 0; // will store the return value of checkUsernamePass()

	infofile.open("credentials.txt", std::ios::app); // open file in append mode
	if (infofile.is_open()) // checks if file is opened
	{  
		clearBuffer(); // clears the buffer

		std::cout << "Enter your name: ";
        	getline(std::cin, personal.m_name); // receive input
		infofile << personal.m_name << ","; // writes input to file

		std::cout << "Enter  your surname: ";
        	getline(std::cin, personal.m_surname); // receive input
		infofile << personal.m_surname << ","; // writes input to file

		std::cout << "Enter your email: ";
        	getline(std::cin, personal.m_email); // receive input
		infofile << personal.m_email << std::endl; // writes input to file

		infofile.close(); // closes the file
		
	}	
	else
	{
	       	std::cerr << "System Error!\n"; // if the file cannot be opened it will prompt error
        }

	loginfile.open("login.txt", std::ios::app); // opens the other file
	if (loginfile.is_open())
        {
		std::cout << "Enter your username: ";

                getline(std::cin, personal.m_login.m_username); // receive input
               	loginfile << personal.m_login.m_username << ","; // writes input to file

                 std::cout << "Enter your password: ";
                 getline(std::cin, personal.m_login.m_password); // receive input
                 loginfile << personal.m_login.m_password << std::endl; // writes input to file
/*
 
 		*This requires the user not to enter a password the same as the username but will finish later

                 returnVal_Name = checkUsernamePass(personal);
                 while (returnVal_Name == 1)
		 {
 	                std::cout << "Password cannot contain your username!\n";
                        std::cout << "Re-enter your password: ";
			// re-enter password until it doesn't contain string
                        getline(std::cin, personal.m_login.m_password); // receive input
                        loginfile << personal.m_login.m_password;

                        returnVal_Name = checkUsernamePass(personal); // assign new return value to variable
                 }
		 loginfile << std::endl;

                 std::cout << "Re-enter your password: ";
                 getline(std::cin, personal.m_login.m_check_pass); // receive input

                 returnVal_Pass = checkPassword(personal); // returns int from checkPassword function
*/
                 while (returnVal_Pass == 1)
		 {
                 	// checks if first entered password matches the second entered password
               	        std::cout << "Passwords don't match.\n";
                        std::cout << "Re-enter your password: ";

                        // re-enter password until correct
                        getline(std::cin, personal.m_login.m_check_pass); // receive input

                        returnVal_Pass = checkPassword(personal); // assign new return value to variable
                 }

                 loginfile.close();
                 std::cout << "Successfully Registered!\n";


	}
	else 
	{
		std::cerr << "System Error!\n"; // if the file cannot be opened it will prompt error
	}
}
