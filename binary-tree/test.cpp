#include <iostream>
#include "bintree.hpp"

int main(int argc, char** argv)
{
    Bintree<int> btree(new Node<int>(5));

    Node<int>* root = btree.retRoot();

    for(int i = 0; i < 10; i++)
        btree.SBinsert(i);

    btree.printTopDown();

    std::cout << "Max depth: " << btree.maxdepth() << std::endl
        << "Min depth: " << btree.mindepth() << std::endl;

    return 0;
}
