#include<bits\stdc++.h>
using namespace std;


int reduce(long ar[], int n);
int main()
{
	long ar[3] = { 1,2,1 };
	cout << reduce(ar, 3) << endl;
	

	
	system("pause");
	return 0;
}

int reduce(long ar[], int n)
{
	sort(ar, ar + n);
	long x = ar[0], res = 1;
	for (int i = 1; i < n; i++)
	{
		if (x != ar[i])
		{
			res++;
			x = ar[i];
		}
	}
	return res;
}