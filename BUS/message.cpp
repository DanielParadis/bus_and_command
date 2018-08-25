#include <iostream>
#include <string>
#include "message.hpp"

std::string message::getAuthor()
{
	return Author;
}

std::string message::getRecipient()
{
	return Recipient;
}

std::string message::getData()
{
	return Data;
}
void message::setAuthor(std::string author)
{
	Author = author;
}

void message::setRecipient(std::string recipient)
{
	Recipient = recipient;
}

void message::setData(std::string data)
{
	Data = data;
}

message::message()
{

}

message::~message()
{

}

void message::outputMessage()
{
	std::cout << Author << " -> " << Recipient << ": " << Data << std::endl;
}