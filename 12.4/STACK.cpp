#include<bits\stdc++.h>
#include"STACK.h"
using std::ostream;
using std::cout;
using std::endl;

Stack::Stack(int n)
{
	{
		pitems = new Item[n];
		pitems[0] = '\0';
		size = n;
		top = 0;
	}
}
Stack::Stack(const Stack& s)
{
	delete[] pitems;
	pitems = new Item[s.size];
	for (int i = 0; i < s.top; i++)
		pitems[i] = s.pitems[i];
	size = s.size;
	top = s.top;
}
Stack::~Stack() { delete[] pitems; cout << "Bye!"; }

bool Stack::isempty() const
{
	if (top != 0)
	{
		cout << "Stack is not empty!" << endl;
		return true;
	}
	cout << "Stack is empty!" << endl;
	return true;
}

bool Stack::isfull() const
{
	if (top != size)
	{
		cout << "Stack is not full!" << endl;
		return false;
	}
	cout << "Stack is full!" << endl;
	return true;
}

bool Stack::push(const Item& item)
{
	if (top < size)
	{
		pitems[top++] = item;
		return true;
	}
	return false;
}

bool Stack::pop(Item& item)
{
	if (top == 0)
		return false;
	item = pitems[--top];
	return true;
}

Stack& Stack::operator=(const Stack& s)
{
	if (this == &s)
		return *this;
	delete[] pitems;
	pitems = new Item[s.size];
	for (int i = 0; i < s.top; i++)
		pitems[i] = s.pitems[i];
	size = s.size;
	top = s.top;
	return *this;
}

ostream& operator<<(ostream& os, const Stack& s)
{
	if (s.top == 0)
	{
		cout << "Current Stack is empty!" << endl;
		return os;
	}
	cout << "Current Stack size is " << s.size << endl;
	for (int i = 0; i < s.top; i++)
		os << s.pitems[i] << endl;
	os << "size: " << s.size << " and top is " << s.top << endl;
	return os;
}