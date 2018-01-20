#include <iostream>
#include <fstream>
#include "substring.hpp"

int main (int argc, char** argv)
{
	std::ifstream infile("stringlist.txt", std::ios::in);
	std::string line = "";

	while(getline(infile, line)) {
		Substr substr(line, 2);
		
		substr.ret_substrings();
		substr.sort_substrings();

		std::cout << "And the winner is... " << substr.ret_minimum() << std::endl;
	}

	infile.close();
	return 0;
}
