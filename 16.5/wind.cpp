#include<bits\stdc++.h>
using namespace std;

template<class T>
int reduce(T ar[], int n);
int main()
{
	long ar[3] = { 1,2,1 };
	cout << reduce(ar, 3) << endl;
	

	
	system("pause");
	return 0;
}

template<class T>
int reduce(T ar[], int n)
{
	sort(ar, ar + n);
	T x = ar[0], res = 1;
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