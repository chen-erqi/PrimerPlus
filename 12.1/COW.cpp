#include<bits\stdc++.h>
#include"COW.h"

using std::cout;
using std::endl;
using std::cin;

Cow::Cow() 
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

//strcpy_s:第二个参数是copy长度！！！！
Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, strlen(nm)+1, nm);
	int len = strlen(ho);
	delete[] hobby;
	hobby = new char[len + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

Cow::~Cow()
{
	cout << "delete this COW." << endl;
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	delete[] hobby;
	weight = c.weight;
	int len = strlen(c.name);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	strcpy_s(name, strlen(c.name) + 1, c.name);
	return *this;
}

void Cow::ShowCow() const
{
	cout << "Name: " << name << endl;
	cout << "Hobby: " << hobby << endl;
	cout << "Weight: " << weight << endl;
	
}