#include "helperFunctions.h"
#include <iostream>

void clearBuffer()
{
        while ((getchar()) != '\n'); // clears buffer
}

void welcome()
{
        // welcome function
	std::cout << "-------------------------------------\n";
        std::cout << "|Welcome to our Registration system!|\n";
	std::cout << "-------------------------------------\n";
        std::cout << "1) Register\n";
        std::cout << "2) Login\n";
        std::cout << "0) Exit\n";
}

