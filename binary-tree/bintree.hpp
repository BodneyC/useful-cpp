#ifndef _BINTREE_
#define _BINTREE_

/** For printTopDown() only, can be removed (with the function) */
#include <iostream> 

template<class Type>
class Node
{
public:
    Type value;
    Node<Type>* left;
    Node<Type>* right;

    Node(Type _value): value(_value), left(0 /*NULL*/), right(0 /*NULL*/) {}
    ~Node(void) = default;
};

template<class Type>
class Bintree
{
public:
    Bintree(Node<Type>* _root): root(_root) {}
    Bintree(Type value): root(new Node<Type>(value)) {}
    Bintree(void): root(0 /*NULL*/) {}
    ~Bintree(void);

    Node<Type>* retRoot(void);
    void delTree(void);
    void insert(Node<Type>* node);
    void insert(Type value);
    Node<Type>* search(Type value);
    void printTopDown(void);
    int maxdepth(void);
    int mindepth(void);

private:
    Node<Type>* root;

    void delTree(Node<Type>* node);
    void insert(Node<Type>* node, Type value);
    void insert(Node<Type>* cur_node, Node<Type>* in_node);
    Node<Type>* search(Node<Type>* node, Type value);
    void printTopDown(Node<Type>* node);
    int maxdepth(Node<Type>* node);
    int mindepth(Node<Type>* node);
};

template<class Type>
Bintree<Type>::~Bintree(void)
{
    delTree(root);
}

template<class Type>
Node<Type>* Bintree<Type>::retRoot(void)
{
    return root;
}

template<class Type>
void Bintree<Type>::delTree(void)
{
    delTree(root);
}

template<class Type>
void Bintree<Type>::delTree(Node<Type>* node)
{
    if(node) {
        delTree(node->left);
        delTree(node->right);
        delete node;
    }
}

template<class Type>
void Bintree<Type>::insert(Type value)
{
    if(!root) 
        root = new Node<Type>(value);
    else 
        insert(root, value);
}

template<class Type>
void Bintree<Type>::insert(Node<Type>* node, Type value)
{
    if(value < node->value)
        if(node->left)
            insert(node->left, value);
        else
            node->left = new Node<Type>(value);
    else
        if(node->right)
            insert(node->right, value);
        else
            node->right = new Node<Type>(value);
}

template<class Type>
void Bintree<Type>::insert(Node<Type>* node)
{
    if(!root)
        root = node;
    else
        insert(root, node);
}

template<class Type>
void Bintree<Type>::insert(Node<Type>* cur_node, Node<Type>* in_node)
{
    if(in_node->value < cur_node->value)
        if(cur_node->left)
            insert(cur_node->left, in_node);
        else
            cur_node->left = in_node;
    else
        if(cur_node->right)
            insert(cur_node->right, in_node);
        else
            cur_node->right = in_node;
}

template<class Type>
Node<Type>* Bintree<Type>::search(Type value)
{
    if(!root)
        return(0 /*NULL*/);
    else
        return search(root, value);
}

template<class Type>
Node<Type>* Bintree<Type>::search(Node<Type>* node, Type value)
{
    if(!node)
        return 0 /*NULL*/;

    if(value == node->value)
        return node;

    if(value < node->value)
        return search(node->left, value);
    else
        return search(node->right, value);
}

template<class Type>
void Bintree<Type>::printTopDown(void)
{
    printTopDown(root);

    std::cout << std::endl;
}

template<class Type>
void Bintree<Type>::printTopDown(Node<Type>* node)
{
    if(!node)
        return;

    std::cout << node->value << " ";

    printTopDown(node->left);
    printTopDown(node->right);
}

template<class Type>
int Bintree<Type>::maxdepth(void)
{
    return maxdepth(root);
}

template<class Type>
int Bintree<Type>::maxdepth(Node<Type>* node)
{
    if(!node || (!(node->left) && !(node->right)))
        return 0;

    int ldepth = maxdepth(node->left);
    int rdepth = maxdepth(node->right);

    return ldepth > rdepth ? ldepth + 1: rdepth + 1;
}

template<class Type>
int Bintree<Type>::mindepth(void)
{
    return mindepth(root);
}

template<class Type>
int Bintree<Type>::mindepth(Node<Type>* node)
{
    if(!node || !(node->left) || !(node->right))
        return 0;

    int ldepth = mindepth(node->left);
    int rdepth = mindepth(node->right);

    return ldepth < rdepth ? ldepth + 1: rdepth + 1;
}
#endif
