#include<bits\stdc++.h>
#include"Golf.h"


golf::golf(){}

golf::golf(const std::string& _Name, int _handicap)
{
	Name = _Name;
	handicap = _handicap;
}

void golf::setgolf()
{
	std::string _Name; int _handicap;
	std::cout << "Please Enter player's Name: ";
	getline(std::cin, _Name);
	std::cout << "Please Enter player's handicap: ";
	std::cin >> _handicap;
	golf g{ _Name, _handicap };
	
	*this = g;  //Notice!!!!!!

	std::cin.get();
	std::cout << std::endl;
}

int golf::setgolf() const
{
	if (this->Name.size() != 0)
		return 1;
	return 0;
}

void golf::showgolf() const
{
	std::cout << std::endl;
	std::cout << "This player's Name: " << this->Name << std::endl;
	std::cout << "This player's handicap: " << this->handicap << std::endl;
}

void golf::sethandicap(const int hc)
{
	this->handicap = hc;
}