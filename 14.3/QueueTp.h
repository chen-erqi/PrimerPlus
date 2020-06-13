#ifndef QueueTp_H_
#define QueueTp_H_
#include<iostream>
#include<string>
using std::string;

template<typename T>
class Queue
{
private:
	struct Node {
		T item;
		struct Node* next;
	};
	Node* front;
	Node* rear;
	int items;
	const int QSIZE;
	Queue(const Queue& q):QSIZE(0){}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = 10);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queueCount() const;
	bool enQueue(const T& item);
	bool dequeue(T& item);
};

template<typename T>
Queue<T>::Queue(int qs) :QSIZE(qs)
{
	front = rear = NULL;
	items = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
bool Queue<T>::isempty() const
{
	return items == 0;
}

template<typename T>
bool Queue<T>::isfull() const
{
	return items == QSIZE;
}

template<typename T>
int Queue<T>::queueCount() const
{
	return items;
}

template<typename T>
bool Queue<T>::enQueue(const T& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<typename T>
bool Queue<T>::dequeue(T& item)
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}

class Worker
{
private:
	string Name;
	int id;
public:
	Worker() :Name("None"), id(0) {}
	Worker(const string& s, long n) :Name(s), id(0) {}
	~Worker() {}
	void Set();
	void Show() const;
};


#endif // !QueueTp_H_

