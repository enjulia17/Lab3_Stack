#pragma once
#include <iostream>

using namespace std;
template<class T>
class Stack
{
public:

	Stack()
	{
		Array = 0;
		size = 0;
		first = 0;
		last = -1;
		DataCount = 0;
	}
	Stack(int _size)
	{
		if (_size < 0)throw logic_error("negative size");
		Array = new const T*[_size];
		size = _size;
		first = 0;
		last = -1;
		DataCount = 0;
	}
	Stack(Stack& lhs)
	{
		Array = new const T*[lhs.size];
		size = lhs.size;
		first = lhs.first;
		last = lhs.last;
		DataCount = lhs.DataCount;
	}

	virtual ~Stack()
	{
		delete[] Array;
	}
	bool IsEmpty()
	{
		return(DataCount==0);
	}
	bool IsFull()
	{
		return(DataCount==size);
	}
	const T** GetMemory()
	{
		return Array;
	}
	 void push (const T& lhs)
	{
		if ((*this).IsFull()) throw logic_error("Container is overflow");
		if (Array == 0) throw logic_error("");
		last++;
		Array[last] = &lhs;
		DataCount++;
	}
	virtual const T& pop()
	{
		if (this->IsEmpty()) throw logic_error("Stack is empty");
		if (Array == 0) throw logic_error("");
		const T* tmp = Array[last];
		Array[last] = 0;
		last--;
		DataCount--;
		return (*tmp);
	}
	int GetSize()
	{
		return size;
	}
	int GetFirst()
	{
		return first;
	}
protected:

const T** Array;
int size;
int first;
int last;
int DataCount;
};