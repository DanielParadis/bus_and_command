#include <iostream>
#include <string>
#include <vector>
#include "message.hpp"
#include "bus.hpp"
#include "node.hpp"

void node::sendMessage(std::string recipient, std::string data)
{
	Buffer.setData(data);
	Buffer.setRecipient(recipient);
	Buffer.setAuthor(Name);
	Bus->Received.push_back(Buffer);
}

std::string node::getMessage()
{
	std::string Buffer;
	std::vector<message>::iterator it = ReceivedMessages.begin();
	if (it != ReceivedMessages.end())
	{
		--totalMessages;
		Buffer = it->getData();
		it = ReceivedMessages.erase(it);
	}
	return Buffer;
}

node::node(bus* ptrBus, std::string name)
{
	Bus = ptrBus;
	Name = name;
	totalMessages = 0;
}

node::~node()
{

}

void node::update()
{
	for (std::vector<message>::iterator it = Bus->Received.begin(); it != Bus->Received.end(); )
	{
		if (it->getRecipient() == Name)
		{
			++totalMessages;
			ReceivedMessages.push_back(*it);
			it = Bus->Received.erase(it);
		}
		else
		{
			++it;
		}
	}
}

bus* node::getBus()
{
	return Bus;
}

int node::getMessageCount()
{
	return totalMessages;
}