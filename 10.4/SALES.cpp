#include<bits\stdc++.h>
#include"SALES.h"

Sales::Sales() {}

Sales::Sales(const double ar[])
{
	double ave = 0.0;
	double _minV = DBL_MAX;
	double _maxV = DBL_MIN;
	for (int i = 0; i < 4; i++)
	{
		this->sales[i] = ar[i];
		ave += ar[i];
		_minV = std::min(_minV, ar[i]);
		_maxV = std::max(_maxV, ar[i]);
	}
	ave /= 4.0;
	this->average = ave;
	this->maxVal = _maxV;
	this->minVal = _minV;
}

void Sales::setSales() 
{
	double ar[4];
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Please Enter the sales of " << i+1 << " quarters: ";
		std::cin >> ar[i];
	}
	Sales s=Sales(ar);
	*this = s;
}

void Sales::showSales() const
{
	for (int i = 1; i <= 4; i++)
		std::cout << "The sales of " << i << " quarter is:" << this->sales[i - 1] << std::endl;
	std::cout << "The max is " << this->maxVal << std::endl;
	std::cout << "The min is " << this->minVal << std::endl;
	std::cout << "The average is " << this->average << std::endl;
}