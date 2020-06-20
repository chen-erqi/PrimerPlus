#include<bits\stdc++.h>
using namespace std;




int main()
{
	char ch;
	int count = 0;
	while (cin.get(ch) && ch != '$')
		count++;
	cin.putback(ch);
	cout << count << endl;
	cout << ch << endl;
	cout << (char)cin.get() << endl;


	count = 0;
	while (cin.get()&&cin.peek() != '$')
	{
		count++;
	}
	cout << count << endl;
	cout << (char)cin.get() << endl;


	system("pause");
	return 0;
}