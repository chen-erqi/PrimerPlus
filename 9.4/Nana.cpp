#include<bits\stdc++.h>
#include"wind.h"

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		int num = n < 4 ? n : 4;
		s.average = 0;
		s.max = INT_MIN;
		s.min = INT_MAX;
		for (int i = 0; i < num; i++)
		{
			s.sales[i] = ar[i];
			s.average += s.sales[i];
			s.max = std::max(s.max, s.sales[i]);
			s.min = std::min(s.min, s.sales[i]);
		}
		s.average /= num;
	}
	void setSales(Sales& s)
	{
		double ar[4];
		for (int i = 1; i <= 4; i++)
		{
			std::cout << "Please Enter the sale of " << i << " quarter:";
			std::cin >> ar[i-1];
			std::cin.get();
		}
		setSales(s, ar, 4);
	}
	void showSales(const Sales& s)
	{
		for (int i = 1; i <= 4; i++)
			std::cout << "The sales of " << i << " quarter is:" << s.sales[i - 1] << std::endl;
		std::cout << "The max is " << s.max << std::endl;
		std::cout << "The min is " << s.min << std::endl;
		std::cout << "The average is " << s.average << std::endl;
	}
}

