// SuffixArrayReadMapper.cpp : Defines the entry point for the application.
//

#include "SuffixArrayReadMapper.h"
#include <string>


int main(int argc, char* argv[])
{
	// minimum argc is 4
	if (argc < 4) {
		std::cout << "Help text" << std::endl;
		return 1;
	}

	//set paths from arguments
	std::string refPath = argv[1];
	std::string readPath = argv[2];
	std::string outPath = argv[3];
	



	std::cout << "Hello From Suffix Array Read Mapper!\n" << std::endl;
	
	std::cout << "Reference File Path: " << refPath << std::endl;
	std::cout << "Read File Path: " << readPath << std::endl;
	std::cout << "Output Path: " << outPath << std::endl;

	return 0;
}
