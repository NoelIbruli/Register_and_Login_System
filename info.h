#pragma once

#ifndef INFO_H_
#define INFO_H_

#include <iostream>
#include <string>

struct LoginInfo
{
	std::string m_username;
	std::string m_password;
	std::string m_check_pass;
};

struct PersonalInfo
{
	std::string m_name;
	std::string m_surname;
	std::string m_email;
	LoginInfo m_login;
};

void reg (struct PersonalInfo personal, std::fstream& infofile, std::fstream& loginfile);
int checkPassword(struct PersonalInfo personal);
int checkUsernamePass(struct PersonalInfo personal);

#endif
