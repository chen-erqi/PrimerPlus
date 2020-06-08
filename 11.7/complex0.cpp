#include<bits\stdc++.h>
#include"complex0.h"
using std::cout;
using std::cin;

Complex::Complex(const double _a, const double _b)
{
	this->a = _a;
	this->b = _b;
}

Complex::~Complex() {};

Complex Complex::operator+(const Complex& x)
{
	return Complex(this->a + x.a, this->b + x.b);
}

Complex Complex::operator-(const Complex& x)
{
	return Complex(this->a - x.a, this->b - x.b);
}

Complex Complex::operator*(const Complex& x)
{
	return Complex((this->a * x.a - this->b * x.b), (this->a * x.b + this->b * x.a));
}

Complex operator*(double z, const Complex& x)
{
	return Complex(z * x.a, z * x.b);
}
Complex Complex::operator~()
{
	return Complex(this->a, -(this->b));
}

std::ostream& operator<<(std::ostream& os,const Complex& x)
{
	cout << "(" << x.a << ", " << x.b << "i)";
	return os;
}

bool operator>>(std::istream& is, Complex& x)
{
	cout << "real: ";
	if(!(cin >> x.a))
		return false;
	cout << "imaginary: ";
	if (!(cin >> x.b))
		return false;
	cout << '\n';
	return true;
}