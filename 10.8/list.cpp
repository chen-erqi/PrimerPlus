#include<bits\stdc++.h>
#include"list.h"

bool myList::push(const Item item)
{
	if (full())
		return false;
	this->items[top++] = item;
	return true;
}

bool myList::empty() const
{
	return top == 0 ? true : false;
}

bool myList::full() const
{
	return top == this->LIMIT ? true : false;
}


/*
	visit这个函数中，使用函数指针pf作为参数。
	pf指向的函数必须参数相同！
*/
void myList::visit(void(*pf)(Item& item))
{
	for (int i = 0; i < top; i++)
		(*pf)(items[i]);			//等于传递(items[i])这个参数给pf指向的函数！
}