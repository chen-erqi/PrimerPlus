#include<bits\stdc++.h>
#include"wine.h"
using std::endl;
using std::cout;
using std::cin;
using std::ostream;

wine::wine(const char* l, int y, const int yr[], const int bot[]) :label(l), years(y)
{
	valarray<int> v1{ yr,(size_t)years };
	valarray<int> v2{ bot,(size_t)years };
	v.first = v1;
	v.second = v2;
}

wine::wine(const char* l, int y) :label(l), years(y)
{
	valarray<int> v1(years);
	valarray<int> v2(years);
	v.first = v1;
	v.second = v2;
}

wine::wine(const wine& w) :label(w.label), years(w.years)
{
	v.first = w.v.first;
	v.second = w.v.second;
}

wine& wine::operator=(const wine& w)
{
	if (this == &w)
		return *this;
	label = w.label;
	years = w.years;
	v.first = w.v.first;
	v.second = w.v.second;
	return *this;
}

wine::~wine(){}

string& wine::Label()
{
	return label;
}

int wine::sum() const
{
	return v.second.sum();
}

void wine::getBottles()
{
	cout << "Enter " << label << " data for " << years << " year(s) :\n";
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> v.first[i];
		cout << "Enter bottles for that year: ";
		cin >> v.second[i];
	}
}

void wine::show() const
{
	cout << "Wine: " << label << endl;
	cout << "\tYear\tBottles\n";
	for (int i = 0; i < years; i++)
	{
		cout << "\t" << v.first[i] << "\t" << v.second[i] << endl;
	}
}