#include <iostream>
#include <fstream>
#include "helperFunctions.h"
#include "info.h"
#include "login.h"

void log(struct PersonalInfo personal, std::fstream& loginfile)
{
	int isPassCorrect;
	int isUsernameCorrect;

	int usernameOffset;
        std::string usernameLine;
        loginfile.open("login.txt", std::ios::in); // open file in read mode
        if (loginfile.is_open())
        {
                std::cout << "Enter Username: ";
                std::cin >> personal.m_login.m_username;
                while (!loginfile.eof())
                {
                        getline(loginfile, usernameLine);
                        if ((usernameOffset = usernameLine.find(personal.m_login.m_username, 0)) != std::string::npos)
                                isUsernameCorrect = 0;
                }
                loginfile.close();
        }
        else
        {
                isUsernameCorrect = 1;
        }

	int passOffset;
        std::string passLine;
        loginfile.open("login.txt", std::ios::in);
        if (loginfile.is_open())
        {
                std::cout << "Enter Password: ";
                std::cin >> personal.m_login.m_password;
                while (!loginfile.eof())
                {
                        getline(loginfile, passLine);
                        if ((passOffset = passLine.find(personal.m_login.m_password, 0)) != std::string::npos)
                                isPassCorrect = 0;
                }
                loginfile.close();
        }
        else
        {
                isPassCorrect = 1;
        }
	
	if (isUsernameCorrect == 0)
	{
		if (isPassCorrect == 0)
			std::cout << "Logged In Successfully!\n";
		else
			std::cout << "Password Incorrect!\n";
	}
	else
	{
		std::cout << "Username Incorrect!\n";
	}
}

