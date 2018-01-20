#include <iostream>
#include "bintree.hpp"

int main(int argc, char** argv)
{
	Bintree<int> btree(new Node<int>(5));

	Node<int>* root = btree.retRoot();

	for(int i = 0; i < 10; i++)
		btree.SBinsert(i);

	btree.print_top_down();

	btree.remove_node(6);

	btree.print_top_down();

	std::cout << "Max depth: " << btree.max_depth() << std::endl
		<< "Min depth: " << btree.min_depth() << std::endl;

	return 0;
}
