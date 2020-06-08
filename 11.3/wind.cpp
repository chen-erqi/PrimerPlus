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
	unsigned long max_steps=0, min_steps=ULONG_MAX, ave_steps = 0.0;
	double target;
	double dstep;
	int N;

	ofstream outfile;
	outfile.open("Nanase.txt");
	cout << "Enter target distance (q to quit): ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	cout << "Enter Test Number: ";
	cin >> N;
	outfile << "The test number is " << N << "; The target distance is " << target << "; The step length is " << dstep << ".\n";
	while (N--)
	{
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		min_steps = min(min_steps, steps);
		max_steps = max(max_steps, steps);
		ave_steps += steps;
		steps = 0;
		result.reset(0.0, 0.0);
	}
	outfile << "The max step is " << max_steps << endl;
	outfile << "The min step is " << min_steps << endl;
	outfile << "The average step is " << ave_steps << endl;
	outfile.close();
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	

	system("pause");
	return 0;
}