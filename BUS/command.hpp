class command
{
private:
	int numFlags;
	std::vector<std::string> flags;
public:
	int getNumFlags();
	void readString(std::string);
	std::string getFlags(int);
	float getFlagf(int);
	double getFlagd(int);
	int getFlagi(int);
};