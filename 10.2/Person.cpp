#include<bits\stdc++.h>
#include"Person.h"

Person::Person(const std::string& ln,const char* fn)
{
	lname = ln;
	strcpy_s(fname, fn);
}

void Person::show() const
{
	std::cout << "Name: " << fname << " " << lname << std::endl;
}

void Person::Formalshow() const
{
	std::cout << "Name: " << lname << " " << fname << std::endl;
}