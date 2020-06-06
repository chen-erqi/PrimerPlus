#include<bits\stdc++.h>
using namespace std;
#include"list.h"


void Print(Item& item)
{
	cout << item << endl;
}
int main()
{
	myList L;
	L.push(1);
	L.push(2);
	L.push(3);
	L.push(4);

	void(*pf)(Item & item) = Print;
	L.visit(pf);

	

	system("pause");
	return 0;
}