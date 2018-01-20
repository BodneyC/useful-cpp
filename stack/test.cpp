#include <iostream>
#include "stack.hpp"

int main(int argc, char** argv)
{
	Stack<int> stack; 

	stack.push(5);
	stack.push(6);
	stack.push(7);

	std::cout << stack.getPoint() << std::endl;
	
	int tmp = stack.getPoint();
	for(int i = 0; i < tmp; i++) {
		std::cout << stack.pop() << " ";
	}
	std::cout << std::endl;

	return 0;
}
