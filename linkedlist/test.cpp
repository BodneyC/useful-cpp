#include "llist.hpp"

int main(int argc, char** argv)
{
    Node<int>* n1 = new Node<int>(0);

    LList<int> llist(n1);

    for(int i = 1; i < 10; i++)
        llist.addTail(i);

    for(int i = 10; i < 20; i++)
        llist.addTail(new Node<int>(i));

    llist.removeVal(5);

    Node<int>* rem = new Node<int>(10);
    llist.addHead(rem);

    llist.removeNode(rem);

    llist.print();

    return 0;
}
