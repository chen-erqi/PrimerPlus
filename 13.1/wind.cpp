#include<bits\stdc++.h>
using namespace std;
#include"classic.h"
void Bravo(const Cd& cd);

int main()
{
	Cd c1("Beatles", "Capito", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;		//把c1的地址赋给pcd
	cout << "Using object directly: \n";
	c1.Report();
	c2.Report();
	cout << "Using type cd* pointer to objects: \n";
	pcd->Report();		//pcd是地址，所以用->,Report是虚函数。根据对象决定。
	pcd = &c2;
	pcd->Report();		//根据对象，选择Classic类的report
	cout << "Calling a function with a Cd reference argumenet: \n";
	Bravo(c1);


	system("pause");
	return 0;
}

void Bravo(const Cd& cd)
{
	cd.Report();
}

