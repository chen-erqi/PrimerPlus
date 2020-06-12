#include<bits\stdc++.h>
#include"wine.h"
using std::endl;
using std::cout;
using std::cin;
using std::ostream;


wine::wine(const char* l, int y, const int yr[], const int bot[]) :string(l), years(y),PAA(VI(yr,y),VI(bot,y)){}
wine::wine(const char* l, int y) :string(l), years(y), PAA(VI(y), VI(y)){}
wine::wine(string& l, int y,PAA v) : string(l), years(y), PAA(v) {}
wine::~wine(){}

string& wine::Label()
{
	return (string&)*this;
}

int wine::sum() const
{
	PAA v = (PAA)*this;
	return v.second.sum();
}

void wine::getBottles()
{
	PAA v = (PAA)*this;
	cout << "Enter " << (string&)*this << " data for " << years << " year(s) :\n";
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> v.first[i];
		cout << "Enter bottles for that year: ";
		cin >> v.second[i];
	}
	*this = wine((string&)*this, years, v);
}

void wine::show() const
{
	cout << "Wine: " << (string&)*this << endl;
	cout << "\tYear\tBottles\n";
	PAA v = (PAA)*this;
	for (int i = 0; i < years; i++)
	{
		cout << "\t" << v.first[i] << "\t" << v.second[i] << endl;
	}
}