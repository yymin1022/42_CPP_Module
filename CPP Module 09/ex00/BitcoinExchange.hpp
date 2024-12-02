#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange{
private:
	std::map<int, float> data;

	BitcoinExchange();

	float strToFloat(std::string str);
	int strToInt(std::string str);
	void readData(std::string line);
	void verifyDate(int year, int month, int day);

public:
	BitcoinExchange(const char *file);
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj);

	float getRate(std::string date);

	class InvalidDateException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class InvalidValueException: public std::exception{
	public:
		virtual const char *what() const throw();
	};
};

#endif
