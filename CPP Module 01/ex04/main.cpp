#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char **argv){
	if(argc != 4){
		std::cout << "Usage: ./Sed [filename] [string 1] [string 2]" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	std::string res;

	std::ifstream file(filename.c_str());
	if(!file.is_open()){
		std::cout << "Error: File Open Error" << std::endl;
		return 1;
	}

	std::stringstream buf;
	buf << file.rdbuf();

	std::string fileContent = buf.str();
	file.close();

	size_t idx = 0;
	while(true){
		idx = fileContent.find(str1, 0);
		if(idx ==std::string::npos || str1 == "")
			break;
		res += fileContent.substr(0, idx);
		res += str2;
		fileContent = fileContent.substr(idx + str1.length());
	}

	res += fileContent;

	std::ofstream resFile((filename + ".replace").c_str());
	if(!resFile.is_open()){
		std::cout << "Error: File Creation Error" << std::endl;
		return 1;
	}

	resFile << res;
	resFile.close();
	std::cout << "File " << filename << " has been replaced and saved as " << filename + ".replace" << std::endl;

	return 0;
}
