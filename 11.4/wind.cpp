#include<bits\stdc++.h>
using namespace std;
#include"mytime.h"


int main()
{
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca: \n";
	cout << aida << "; " << tosca << endl;
	cout << "Aida + Tosca: " <<aida + tosca << endl;
	cout << "Aida * 1.17: " << aida * 1.17 << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
	

	system("pause");
	return 0;
}