#ifndef _STACK_
#define _STACK_

template<class Type>
class Stack
{
private:
	int width;
	int point;
	Type* arr;

public:
	Stack(int _width = 50);
	~Stack();

	bool push(const Type &entry);
	Type pop(void);
	int getPoint(void);
};

template<class Type>
Stack<Type>::Stack(int _width): width(_width), point(0)
{
	arr = new Type[width];
}

template<class Type>
Stack<Type>::~Stack(void)
{
	delete[] arr;
}

template<class Type>
bool Stack<Type>::push(const Type &entry)
{
	if(point == width - 1)
		return false;

	arr[point++] = entry;
	return true;
}

template<class Type>
Type Stack<Type>::pop(void)
{
	if(point >= 0)
		return arr[--point];
	
	return 0;
}

template<class Type>
int Stack<Type>::getPoint(void)
{
	return point;
}

#endif
