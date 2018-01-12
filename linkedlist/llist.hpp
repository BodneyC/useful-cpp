#ifndef LLIST
#define LLIST

#include <iostream>

template<class Type>
struct Node
{
    Type value_t;
    Node<Type>* next;
};

template<class Type>
class LList
{
public:
    Node<Type>* head;
    Node<Type>* tail;

    LList(Node<Type>* initNode): head(initNode), tail(initNode) {}
    LList(): head(NULL), tail(NULL) {}
    LList(Type value_t);
    ~LList();

    void addHead(Node<Type>* node);
    void addTail(Node<Type>* node);
    void addHead(Type value_t);
    void addTail(Type value_t);
    void removeVal(Type value_t);
    void removeNode(Node<Type> node);
    void print(std::ostream& stream = std::cout) const;
};

template<class Type>
LList<Type>::LList(Type value_t)
{
    Node<Type> tmp = new Node<Type>();
    head = tmp;

    head->value_t = value_t;
    tail = head;
    tail->next = NULL;
}

template<class Type>
LList<Type>::~LList()
{
    Node<Type>* tmp = head;

    while(tmp) {
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

template<class Type>
void LList<Type>::addHead(Node<Type>* node)
{
    node->next = head;
    head = node;
    if(!(head->next))
        head->next = tail;
}

template<class Type>
void LList<Type>::addHead(Type value_t)
{
    Node<Type>* tmp = new Node<Type>();
    tmp->value_t = value_t;

    tmp->next = head;
    head = tmp;
    if(head->next == NULL)
        head->next = tail;
}

template<class Type>
void LList<Type>::addTail(Node<Type>* node)
{
    tail->next = node;
    tail = node;
}

template<class Type>
void LList<Type>::addTail(Type value_t)
{
    Node<Type>* tmp = new Node<Type>();
    tmp->value_t = value_t;

    tail->next = tmp;
    tail = tmp;
}

template<class Type>
void LList<Type>::removeVal(Type value_t)
{
    Node<Type>* tmp = &head;

    while((*tmp)->next)
        if((*tmp)->value_t = value_t)
            removeNode(*tmp);
}

template<class Type>
void LList<Type>::removeNode(Node<Type> node)
{
    Node<Type>* tmp = &head;

    while((*tmp) != node)
        tmp = &(*tmp)->next;

    *tmp = node->next;
}

template<class Type>
void LList<Type>::print(std::ostream& stream) const
{
    Node<Type>* tmp = new Node<Type>;
    tmp = head;
    int i = 0;

    stream << "Printing from head:" << std::endl;

    while(tmp) {
        stream << "Node: " << i << "\tValue: " << tmp->next;
        i++;
    }
}

#endif
