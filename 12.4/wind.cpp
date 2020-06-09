#include<bits\stdc++.h>
using namespace std;
#include"STACK.h"

int main()
{
	{
		Stack s1{ 5 };
		cout << s1;
		s1.push(1);
		cout << s1;
		Item x;
		s1.pop(x);
		cout << x << endl;
		cout << s1;
		for (int i = 0; i < 5; i++)
			s1.push(i);
		cout << s1;
		s1.isfull();

		Stack s2(s1);
		cout << s2;

		Stack s3 = s1;
		cout << s3;
	}





	system("pause");
	return 0;
}