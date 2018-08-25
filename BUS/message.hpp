class message
{
private:
	// We privately define the data of the message so that no one can access them without using access functions
	std::string Author;
	std::string Recipient;
	std::string Data;
public:
	// Here we are defining our setter and our getter functions
	std::string getAuthor();
	std::string getRecipient();
	std::string getData();
	void setAuthor(std::string);
	void setRecipient(std::string);
	void setData(std::string);
	message();
	~message();
	void outputMessage();
};