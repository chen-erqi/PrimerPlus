#include<bits\stdc++.h>
#include"Plorg.h"

Plorg::Plorg(const std::string& _Name, int _CI)
{
	this->Name = _Name;
	this->CI = _CI;
}

void Plorg::SetPlorg()
{
	std::cout << "Please Enter Name: ";
	std::string _Name;
	getline(std::cin, _Name);
	while (_Name.size() >= 19)
	{
		std::cout << "The current length is: " << _Name.size() << std::endl;
		std::cout << "The maximum length of Name can't be bigger than 19!" << std::endl;
		std::cout << "Please ReEnter Name:";
		getline(std::cin, _Name);
	}
	Plorg s{ _Name };
	*this = s;
}

void Plorg::modifyCI(int newCI)
{
	this->CI = newCI;
}

void Plorg::showPlorg() const
{
	std::cout << std::endl;
	std::cout << "Name: " << this->Name << std::endl;
	std::cout << "CI: " << this->CI << std::endl;
}