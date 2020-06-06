#include<bits/stdc++.h>
#include"BankAccount.h"

BankAccount::BankAccount(const std::string& _Name, const std::string& _AccountNum, double _balance)
{
	Name = _Name;
	AccountNum = _AccountNum;
	balance = _balance;
}

void BankAccount::show() const
{
	std::cout << "Name: " << Name << std::endl;
	std::cout << "AccountNum: " << AccountNum << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::push(const double cash) 
{
	this->balance += cash;
}

void BankAccount::take(const double cash)
{
	this->balance -= cash;
}