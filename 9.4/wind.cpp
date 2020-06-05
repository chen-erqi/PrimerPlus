#include<bits\stdc++.h>
#include"wind.h"
using namespace std;



int main()
{
	SALES::Sales s1, s2;
	SALES::setSales(s1);
	double ar[4] = { 1.2,2.2,3.2,4.2 };
	SALES::setSales(s2, ar, 4);
	cout << endl << endl;
	cout << "The s1 is: " << endl;
	SALES::showSales(s1);
	cout << "The s2 is: " << endl;
	SALES::showSales(s2);

	system("pause");
	return 0;
}