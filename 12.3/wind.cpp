#include<bits\stdc++.h>
using namespace std;
#include"stock.h"

int main()
{
	Stock stocks[4] = {
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5)
	};

	cout << "Stock holdings: \n";
	for (int i = 0; i < 4; i++)
		cout << stocks[i];
	const Stock* top = &stocks[0];
	for (int i = 1; i < 4; i++)
		top = &top->topval(stocks[i]);
	cout << "\n Most valuable holiding: " << *top;
	cin.get();



	system("pause");
	return 0;
}