#include<bits\stdc++.h>
#include"classic.h"
using std::cout;
using std::endl;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy_s(performers, strlen(s1) + 1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "     Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "  Playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* _major, const char* s1, const char* s2, int n, double x) : Cd(s1,s2,n,x)
{
	major = new char[strlen(_major) + 1];
	strcpy_s(major, (int)strlen(_major) + 1, _major);
}

Classic::Classic(const char* _major, const Cd& cd) : Cd(cd)
{
	major = new char[strlen(_major) + 1];
	strcpy_s(major, strlen(_major) + 1, _major);
}

Classic::~Classic()
{
	delete[] major;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);		//*this=c
	delete[] major;
	major = new char[strlen(c.major) + 1];
	strcpy_s(major, strlen(c.major) + 1, c.major);
	return *this;
}

void Classic::Report() const
{
	Cd::Report();			//Report the *this of Cd 
	cout << "Major is: " << major << endl;
}

