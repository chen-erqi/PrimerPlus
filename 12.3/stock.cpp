#include<bits\stdc++.h>
#include"stock.h"
using std::cout;
using std::endl;
using std::ios_base;

Stock::Stock()
{
	cout << "Default constructor called: \n";
	company = new char[1];
	company[0] = '\0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
{
	cout << "Constructor using " << co << " called\n";
	company = new char[strlen(co) + 1];
	strcpy_s(company, strlen(co) + 1, co);

	if (n < 0)
	{
		cout << "Number of shares can't be negative; " << company << "'s shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	cout << company << "has been deleted! \n";
	delete[] company;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
		cout << "Number of shares purchase can't be negative. Transaction is aborted. \n";
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
		cout << "Number of shares sole can't be negative. Transaction is aborted. \n";
	else if (num > shares)
		cout << "You can't sell more than you have! Transaction is aborted. \n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(long num, double price)
{
	share_val = price;
	set_tot();
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& s) 
{
	ios_base::fmtflags sorig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << s.company << "'s shares: " << s.shares << ".\n" << "Share Price: $" << s.share_val << '\n';
	os.precision(2);
	os << " Total Worth: $" << s.total_val << ".\n";
	os.setf(sorig, ios_base::floatfield);
	os.precision(prec);
	return os;
}