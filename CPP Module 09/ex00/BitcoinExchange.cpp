#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
	if(this != &obj){
		*this = obj;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const char *file){
	std::ifstream data;
	data.open(file);
	if(!data.is_open()){
		std::cout << "Error: fail to open data file\n";
		std::exit(1);
	}

	std::string line;
	std::getline(data, line);
	while(getline(data, line)){
		if(line.size() > 11)
			readData(line);
	}
}

float BitcoinExchange::getRate(std::string date){
	if(date[4] != '-' || date[7] != '-')
		throw InvalidDateException();

	int year = strToInt(date.substr(0, 4));
	int month = strToInt(date.substr(5, 2));
	int day = strToInt(date.substr(8, 2));

	verifyDate(year, month, day);

	int key = ((((year << 4) | month) << 5) | day);
	std::map<int, float>::iterator iter = data.upper_bound(key);
	if(iter != data.begin())
		return ((--iter)->second);
	else
		throw InvalidDateException();
}

float BitcoinExchange::strToFloat(std::string str){
	std::stringstream ss(str.c_str());
	float val;
	ss >> val;
	if(ss.fail())
		throw InvalidValueException();
	return (val);
}

int BitcoinExchange::strToInt(std::string str){
	int length = static_cast<int>(str.size());
	for(int i = 0; i < length; i++){
		if(!std::isdigit(str[i]))
			throw InvalidDateException();
	}

	std::stringstream ss(str.c_str());
	int val;
	ss >> val;
	if(ss.fail())
		throw InvalidDateException();
	return (val);
}

void BitcoinExchange::readData(std::string line){
	try{
		int key = strToInt(line.substr(0, 4));
		key = (key << 4) | strToInt(line.substr(5, 2));
		key = (key << 5) | strToInt(line.substr(8, 2));

		float value = strToFloat(line.substr(11));
		data.insert(std::make_pair(key, value));
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}

void BitcoinExchange::verifyDate(int year, int month, int day){
	static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(year < 1 || month < 1 || month > 12)
		throw InvalidDateException();
	if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		&& (day < 1 || day > days[month] + 1))
		throw InvalidDateException();
	if(day < 1 || day > days[month])
		throw InvalidDateException();
}

const char *BitcoinExchange::InvalidDateException::what() const throw(){
	return ("Error: Invalid Date");
}

const char *BitcoinExchange::InvalidValueException::what() const throw(){
	return ("Error: Invalid Rate");
}
