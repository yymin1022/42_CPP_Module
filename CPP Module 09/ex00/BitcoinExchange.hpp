#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange{
private:
	BitcoinExchange();

	float intToFloat(std::string str);
	int floatToInt(std::string str);
	void readData(std::string line);
	void verifyDate(int* days, int year, int month, int day);

public:
	BitcoinExchange(const char *file);
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj);

	float getRate(std::string date);
};

#endif
