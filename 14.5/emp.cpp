#include<bits\stdc++.h>
#include"emp.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

abstr_emp::~abstr_emp(){}

void abstr_emp::ShowAll() const
{
	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter First Name: ";
	getline(cin, fname);
	cout << "Enter Last Name: ";
	getline(cin, lname);
	cout << "Enter the job: ";
	getline(cin, job);
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	cout << e.fname << " " << e.lname << "'s job: " << e.job << endl;
	return os;
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	cin.get();
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << inchargeof << endl;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	getRep();
}

void highfink::ShowAll() const
{
	manager::ShowAll();
	cout << "ReportsTo: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	manager::SetAll();
	fink::ReportsTo();
}

