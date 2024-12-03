#include "BitcoinExchange.hpp"

float getValue(std::string line);
void printResult(std::string line, float value, float rate);
void readFile(std::ifstream& input, char *file);
void verifyLine(std::string line);

int main(int argc, char** argv){
	if(argc != 2){
		std::cerr << "Usage: BitcoinExchange <filename>" << std::endl;
		std::exit(1);
	}

	BitcoinExchange be = BitcoinExchange("data.csv");

	std::ifstream input;
	readFile(input, argv[1]);

	std::string line;
	std::getline(input, line);
	while(std::getline(input, line)){
		try{
			verifyLine(line);
			printResult(line, getValue(line.substr(13)), be.getRate(line.substr(0, 10)));
		}catch(const std::string& e){
			std::cerr << e << std::endl;
		}catch(const BitcoinExchange::InvalidDateException& e){
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}

float getValue(std::string line){
	int dotCnt = 0;
	int length = static_cast<int>(line.size());

	int i = 0;
	if(line[i] == '+' || line[i] == '-')
		i++;
	while(i < length){
		if(line[i] == '.')
			dotCnt++;
		else if(!std::isdigit(line[i]))
			throw std::string("Error: Invalid Value");
		i++;
	}

	if(dotCnt > 1)
		throw std::string("Error: Invalid Value");

	float value;
	std::stringstream ss(line.c_str());
	ss >> value;
	if(ss.fail())
		throw std::string("Error: Invalid Value");
	if(value < 0.0f)
		throw std::string("Error: Negative Number not allowed");
	if(value > 1000.0f)
		throw std::string("Error: Large Number not allowed");
	return (value);
}

void printResult(std::string line, float value, float rate){
	std::cout << line.substr(0, 10) << " => " << value << " = " << value * rate << std::endl;
}

void readFile(std::ifstream& input, char *file){
	input.open(file);
	if(!input.is_open()){
		std::cout << "Error: Failed to open file" << std::endl;
		std::exit(1);
	}
}

void verifyLine(std::string line){
	if(line.size() < 14)
		throw(std::string("Error: bad input => ") + line);
	if(line[10] != ' ')
		throw(std::string("Error: bad input => ") + line);
	if(line[11] != '|')
		throw(std::string("Error: bad input => ") + line);
	if(line[12] != ' ')
		throw(std::string("Error: bad input => ") + line);
}
