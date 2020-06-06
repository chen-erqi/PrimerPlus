#include<bits\stdc++.h>
using namespace std;
#include"Person.h"


int main()
{
	Person one;
	Person two("nanase");
	Person three("nanase", "nishino");

	one.show();
	one.Formalshow();

	two.show();
	two.Formalshow();

	three.show();
	three.Formalshow();

	system("pause");
	return 0;
}