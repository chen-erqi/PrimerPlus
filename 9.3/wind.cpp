#include<bits\stdc++.h>
using namespace std;


const int BUF = 512;
char buffer[BUF];
int main()
{
	struct chaff {
		char dross[20];
		int slag;
	};
	chaff* dp1 = new (buffer)chaff[2];
	chaff* dp2 = new chaff[2];

	for (int i = 0; i < 2; i++)
	{
		cout << "Please Enter the dross:";
		cin.getline((dp1 + i)->dross, 20);
		cout << "Please Enter the slag:";
		cin >> (dp1 + i)->slag;
		cin.get();
	}
	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "The dross of dp1[" << i << "] is " << "\"" << (dp1 + i)->dross << "\"" << endl;
		cout << "The slag of dp1[" << i << "] is " << (dp1 + i)->slag << endl;
	}


	system("pause");
	return 0;
}