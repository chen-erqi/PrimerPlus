#include<bits\stdc++.h>
using namespace std;
#include"Cpmv.h"






int main()
{
	//手动析构之后 变量名还在堆中 当程序结束还会再释放一次
	Cpmv a1;
	a1.Display();

	Cpmv a2("Nanase", "Asuka");
	a2.Display();

	Cpmv a3(a2);
	a3.Display();

	Cpmv a4(a2 + a3);
	a4.Display();

	Cpmv a5 = a2;
	a5.Display();

	Cpmv a6 = a2 + a3;
	a6.Display();



	system("pause");
	return 0;
}