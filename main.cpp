#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "BUS/message_bus.hpp"

int main()
{
	bus BUS;
	node Node(&BUS, "test");
	command Command;
	Node.sendMessage("test", "string hello int 1 double 1.0 float 3.14");
	Node.update();
	Command.readString(Node.getMessage());
	std::cout << Command.getFlags(0) << " " << Command.getFlags(1) << " " << Command.getFlags(2) << " " <<
		Command.getFlagi(3) << " " << Command.getFlags(4) << " " << Command.getFlagd(5) << " " <<
		Command.getFlags(6) << " " << Command.getFlagf(7) << std::endl;
	std::cin.get();
	return 0;
}