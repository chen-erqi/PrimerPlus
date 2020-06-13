#include<bits\stdc++.h>
#include"QueueTp.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


void Worker::Show() const
{
	cout << "Name: " << Name << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Set()
{
	cout << "Enter Worker's Name: ";
	getline(cin, Name);
	cout << "Enter worker's ID: ";
	cin >> id;
	cin.get();
}

