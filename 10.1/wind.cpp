#include<bits\stdc++.h>
using namespace std;
#include"BankAccount.h"



int main()
{
	BankAccount S{ "Nanase","0525",100 };
	S.show();
	S.push(200);
	S.show();
	S.take(50);
	S.show();


	system("pause");
	return 0;
}