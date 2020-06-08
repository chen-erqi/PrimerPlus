#include<bits\stdc++.h>
using namespace std;
#include"vec.h"



int main()
{
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	ofstream outfile;
	outfile.open("Nanase.txt");
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outfile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			outfile << steps << ": (x,y) = " << "(" << result.xval() << "," << result.yval() << ")" << endl;
			steps++;
		}
		outfile << "After " << steps << " steps,the subject has the following location: \n";
		outfile << result << endl;
		result.polar_mode();
		outfile << " or\n" << result << endl;
		outfile << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	outfile.close();
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	

	system("pause");
	return 0;
}