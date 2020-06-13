#include<bits\stdc++.h>
using namespace std;
#include"emp.h"

//(1).string类已经定义有赋值运算符
//(2).派生类将修改它们的行为
//(3).防止多次拷贝
//(4).数据都在父类中
//(5).派生类可以自动调用基类的友元
//(6).会被强转为基类

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "Curly Kew");
	hf.ShowAll();

	cout << "Press a key for next phase: \n";
	cin.get();
	cin.get();										//过滤换行符
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp * pointer: \n";
	abstr_emp* tri[4] = { &em,&fi,&hf,&hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();




	system("pause");
	return 0;
}



