#include<bits\stdc++.h>
#include"QUEUE.h"
using std::cout;
using std::endl;

//Queue methods
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

//Add item to queue
bool Queue::enqueue(const Item& iteml)
{
	if (isfull())
		return false;
	Node* add = new Node;	//create new Node
//on failure,new throws std::bad_alloc exception
	add->item = iteml;		//set node pointers
	add->next = nullptr;	//or nullptr
	items++;
	if (front == nullptr)	//if queue is empty
		front = add;		//place item at front
	else
		rear->next = add;	//else place at rear
	rear = add;				//have rear point to new mode
	return true;
}

//Place front item into item variable and remove from queue
bool Queue::dequeue(Item& item)
{
	if (front == nullptr)
		return false;
	item = front->item;			//set item to first item in queue
	items--;
	Node* temp = front;			//save location of first item
	front = front->next;		//reset front to next item
	delete temp;				//delete former first item
	if (items == 0)
		rear = nullptr;
	return true;
}

//time set to a random value in the range 1-3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}