#ifdef __cpluplus

#include <iostream>
#include <random>

int main(int argc, char** argv)
{
	int rand_max;
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());

	std::cout << "Max val: ";
	std::cin >> rand_max;
	std::cout << std::endl;

	std::uniform_int_distribution<int> dist(1, rand_max);

	std::cout << dist(generator) << std::endl;

	return 0;
}

#else

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	int rand_max;
	srand((unsigned int) time(NULL));

	printf("Max val: ");
	scanf(" %d", &rand_max);

	printf("%d\n", rand() % (rand_max + 1));

	return 0;
}

#endif
