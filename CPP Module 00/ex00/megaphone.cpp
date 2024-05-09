#include <iostream>

void print_upper(const std::string &str){
	for(size_t i = 0; i < str.length(); i++){
		std::cout << static_cast<char>(std::toupper(str[i]));
	}
}

int main(int argc, char **argv){
	if(argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}else{
		for(int i = 1; i < argc; i++){
			print_upper(argv[i]);
		}
	}

	std::cout << std::endl;

	return 0;
}
