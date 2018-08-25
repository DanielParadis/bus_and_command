#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "message.hpp"
#include "bus.hpp"
#include "node.hpp"
#include "command.hpp"

int command::getNumFlags()
{
	return numFlags;
}
void command::readString(std::string String)
{
	numFlags = 0;
	flags.clear();
	std::string buffer = String;
	std::string flag;
	bool EOL = false;
	for (int i = 0; EOL == false; ++i)
	{
		if (buffer[i] != ' ' && buffer[i] != '\0')
		{
			flag += buffer[i];
		}
		else
		{
			flags.push_back(flag);
			++numFlags;
			flag = std::string{};
			if (buffer[i] == '\0')
				EOL = true;
		}
	}
}
std::string command::getFlags(int numFlag)
{
	if (numFlag < 0 || numFlag >= numFlags)
	{
		std::cout << "Invalid flag request!\n";
		return std::string{};
	}
	else
	{
		return flags[numFlag];
	}
}
float command::getFlagf(int numFlag)
{
	if (numFlag < 0 || numFlag >= numFlags)
	{
		std::cout << "Invalid flag request!\n";
		return 0;
	}
	else
	{
		std::stringstream sstr(flags[numFlag]);
		float buf;
		if (!(sstr >> buf))
		{
			std::cout << "Could not get float from " << flags[numFlag] << std::endl;
		}
		return buf;
	}
}
double command::getFlagd(int numFlag)
{
	if (numFlag < 0 || numFlag >= numFlags)
	{
		std::cout << "Invalid flag request!\n";
		return 0;
	}
	else
	{
		std::stringstream sstr(flags[numFlag]);
		double buf;
		if (!(sstr >> buf))
		{
			std::cout << "Could not get double from " << flags[numFlag] << std::endl;
		}
		return buf;
	}
}
int command::getFlagi(int numFlag)
{
	if (numFlag < 0 || numFlag >= numFlags)
	{
		std::cout << "Invalid flag request!\n";
		return 0;
	}
	else
	{
		std::stringstream sstr(flags[numFlag]);
		int buf;
		if (!(sstr >> buf))
		{
			std::cout << "Could not get int from " << flags[numFlag] << std::endl;
		}
		return buf;
	}
}