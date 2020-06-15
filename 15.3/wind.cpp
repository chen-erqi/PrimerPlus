#include<bits\stdc++.h>
using namespace std;
#include"mean.h"


double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geomettric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>:";
		}
		catch (_error& e)
		{
			cout << e.what();
			cout << "Error message: \n";
			e.mesg();
			break;
		}
	}
	cout << "Bye!\n";




	system("pause");
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);    //注意这里要传入参数！！！
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	return sqrt(a * b);
}