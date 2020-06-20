#include<bits\stdc++.h>
#include"emp.h"
using namespace std;

abstr_emp::abstr_emp() :fname("NULL"), lname("NULL"), job("NULL") {}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j) :fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const
{
	cout << "FirstName: " << fname << endl;
	cout << "LastName: " << lname << endl;
	cout << "Job is: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter FirstName: ";
	getline(cin, fname);
	cout << "Enter LastName: ";
	getline(cin, lname);
	cout << "Enter Position: ";
	getline(cin, job);
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname << ", " << e.job << endl;
	return os;
}

abstr_emp::~abstr_emp() {}

void abstr_emp::writeall(ofstream& ofs)
{
	ofs << fname << "\n";
	ofs << lname << "\n";
	ofs << job << "\n";
}

void abstr_emp::getall(ifstream& ifs)
{
	getline(ifs, fname);
	getline(ifs, lname);
	getline(ifs, job);
}

employee::employee() :abstr_emp() {}

employee::employee(const string& fn, const string& ln, const string& j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
	cout << "Employee's info: \n";
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	cout << "Enter Employee's info: \n";
	abstr_emp::SetAll();
}

void employee::writeall(ofstream& ofs)
{
	ofs << "0\n";
	abstr_emp::writeall(ofs);
}

void employee::getall(ifstream& ifs)
{
	cout << "Get Employee's info from TXT.\n";
	abstr_emp::getall(ifs);
}

manager::manager() :abstr_emp(),in_chargeof(0) {}

manager::manager(const string& fn, const string& ln, const string& j, int ico) : abstr_emp(fn, ln, j), in_chargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), in_chargeof(ico) {}

manager::manager(const manager& m) : abstr_emp(m),in_chargeof(m.in_chargeof){}

void manager::ShowAll() const
{
	cout << "Manager's info: \n";
	abstr_emp::ShowAll();
	cout << "InChargrof: " << InChargeOf() << endl;
}

void manager::SetAll()
{
	cout << "Enter Manager's info: \n";
	abstr_emp::SetAll();
	cout << "Enter InChargeof: ";
	if (!isdigit(cin.peek()))//·ÀÊÖ¼ú
		exit(EXIT_FAILURE);
	(cin >> in_chargeof).get();
}

void manager::writeall(ofstream& ofs)
{
	ofs << "1\n";
	abstr_emp::writeall(ofs);
	ofs << in_chargeof << endl;
}

void manager::getall(ifstream& ifs)
{
	cout << "Get the manager's info from TXT\n";
	abstr_emp::getall(ifs);
	ifs >> in_chargeof;
}

fink::fink() :abstr_emp() {}

fink::fink(const string& fn, const string& ln, const string& j, const string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const string& rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const
{
	cout << "Fink's info: \n";
	abstr_emp::ShowAll();
	cout << "Reportsto: " << ReportsTo() << endl;
}

void fink::SetAll()
{
	cout << "Enter Fink's info: \n";
	abstr_emp::SetAll();
	getReportsTo();
}

void fink::writeall(ofstream& ofs)
{
	ofs << "2\n";
	abstr_emp::writeall(ofs);
	writeReportsTo(ofs);
}

void fink::getall(ifstream& ifs)
{
	cout << "Get Fink's info from TXT\n";
	abstr_emp::getall(ifs);
	ifs >> reportsto;
}

highfink::highfink() :abstr_emp(), manager(), fink() {}

highfink::highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico) :
	abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp& e, const string& rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager& m, const string& rpo) : abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const
{
	cout << "Highfink's info: \n";
	abstr_emp::ShowAll();
	cout << "InChargeOf: " << manager::InChargeOf() << endl;
	cout << "ReportsTo: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	cout << "Enter HighFink's info\n";
	abstr_emp::SetAll();
	manager::getInCharge();
	fink::getReportsTo();
}

void highfink::writeall(ofstream& ofs)
{
	ofs << "3\n";
	abstr_emp::writeall(ofs);
	manager::wirteInCharge(ofs);
	fink::writeReportsTo(ofs);
}

void highfink::getall(ifstream& ifs)
{
	cout << "Get HighFink's info from TXT.\n";
	abstr_emp::getall(ifs);
	manager::readInCharge(ifs);
	fink::readReportsTo(ifs);
}