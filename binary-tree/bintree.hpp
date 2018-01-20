#ifndef _BINTREE_
#define _BINTREE_

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

/** For printTopDown() only, can be removed (with the function) */
#include <iostream> 

template<class Type>
class Node
{
public:
	Type value;
	int height;
	Node<Type>* left;
	Node<Type>* right;

	Node(Type _value): 
		value(_value), height(0), left(0 /*NULL*/), right(0 /*NULL*/) {}
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
	void SBinsert(Type value);

private:
	Node<Type>* root;

	void delTree(Node<Type>* node);
	void insert(Node<Type>* node, Type value);
	void insert(Node<Type>* cur_node, Node<Type>* in_node);
	Node<Type>* search(Node<Type>* node, Type value);
	void printTopDown(Node<Type>* node);
	int maxdepth(Node<Type>* node);
	int mindepth(Node<Type>* node);
	Node<Type>* SBinsert(Node<Type>* node, Type value);
	Node<Type>* rotateL(Node<Type>* nodeR);
	Node<Type>* rotateR(Node<Type>* nodeL);

	int height(Node<Type>* node)
	{
		return !node ? -1 : node->height;
	}
};

/*************** Cons and dees ****************/

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

/*************** Self-balanced insert ****************/

template<class Type>
void Bintree<Type>::SBinsert(Type value)
{
	root = SBinsert(root, value);
}

template<class Type>
Node<Type>* Bintree<Type>::SBinsert(Node<Type>* node, Type value)
{
	if(node == 0 /*NULL*/) {
		node = new Node<Type>(value);
	} else if(value < node->value) {
		node->left = SBinsert(node->left, value);
		if(height(node->left) - height(node->right) == 2) {
			if(value < node->left->value){
				node = rotateL(node);
			} else {
				node->left = rotateR(node->left);
				node = rotateL(node);
			}
		}
	} else {
		node->right = SBinsert(node->right, value);
		if(height(node->right) - height(node->left) == 2) {
			if(value > node->right->value){
				node = rotateR(node);
			} else {
				node->right = rotateL(node->right);
				node = rotateR(node);
			}
		}
	}
	node->height = MAX(height(node->left), height(node->right)) + 1;

	return node;
}

template<class Type>
Node<Type>* Bintree<Type>::rotateL(Node<Type>* nodeR)
{
	Node<Type>* nodeM = nodeR->left;
	nodeR->left = nodeM->right;
	nodeM->right = nodeR;
	
	nodeR->height = MAX(height(nodeR->left), height(nodeR->right)) + 1;
	nodeM->height = MAX(height(nodeM->left), nodeR->height) + 1;

	return nodeM;
}

template<class Type>
Node<Type>* Bintree<Type>::rotateR(Node<Type>* nodeL)
{
	Node<Type>* nodeM = nodeL->right;
	nodeL->right = nodeM->left;
	nodeM->left = nodeL;
	
	nodeL->height = MAX(height(nodeL->left), height(nodeL->right)) + 1;
	nodeM->height = MAX(height(nodeM->right), nodeL->height) + 1;

	return nodeM;
}

/*************** Regular insert (val) ****************/

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
	node->height++;

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

/*************** Regular insert (node) ****************/

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
	cur_node->height++;

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

/*************** Search ****************/

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

/*************** Print tree ****************/

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

	std::cout << node->value << " L";

	printTopDown(node->left);
	std::cout << " R";
	printTopDown(node->right);
}

/*************** Maximum depth of tree ****************/

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

/*************** Minimum depth of tree ****************/

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
