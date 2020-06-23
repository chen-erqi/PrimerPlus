#include<bits\stdc++.h>
#include"Cpmv.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


//注意 指针一定要new！！！！！！
Cpmv::Cpmv() 
{
	cout << "Using defalut constructed function" << endl;
	pi = new Info;//Notice!!
	pi->qcode = "NULL";
	pi->zcode = "NULL";
}

Cpmv::Cpmv(string q, string z)
{
	cout << "Using constructed function by string q and string z" << endl;
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv& cp)
{
	cout << "Using constructed function by lvalue of Cpmv" << endl;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv&& mv)
{
	cout << "Using constructed function by rvalue of Cpmv" << endl;
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "NULL";
	mv.pi->zcode = "NULL";
}

Cpmv::~Cpmv() {
	cout << "Using delete function\n";
	delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	cout << "Using = function by lvalue of Cpmv" << endl;
	if (this == &cp)
		return *this;
	//赋值时已经初始化 所以不用new pi
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
	cout << "Using = function by rvalue of Cpmv" << endl;
	if (this == &mv)
		return *this;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "NULL";
	mv.pi->zcode = "NULL";
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
	cout << "A + B" << endl;
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	return temp;
}

void Cpmv::Display() const
{
	cout << pi->qcode << " " << pi->zcode << endl;
}
 

