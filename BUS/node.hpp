class node
{
private:
	// Our node will have a name. This will be used to label messages, and messages will be sent to that name
	std::string Name;
	// We have a buffer to handle our current message
	message Buffer;
	bus* Bus;
	int totalMessages;
public:
	std::vector<message> ReceivedMessages;
	void sendMessage(std::string, std::string);
	std::string getMessage();
	node(bus*, std::string);
	~node();
	void update();
	bus* getBus();
	int getMessageCount();
};