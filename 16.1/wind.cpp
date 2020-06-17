#include<bits\stdc++.h>
using namespace std;



void fun1(string& s)
{
	int L = 0, R = s.size() - 1;
	while (L <= R)
	{
		if (s[L] != s[R])
		{
			cout << "False!" << endl;
			return;
		}
		L++;
		R--;
	}
	cout << "True!" << endl;
}
int main()
{
	string s;
	getline(cin, s);
	fun1(s);
	


	system("pause");
	return 0;
}