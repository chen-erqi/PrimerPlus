#ifndef complex0_H_
#define complex0_H_
#include<iostream>

class Complex {
private:
	double a;
	double b;
public:
	Complex(const double _a=0.0, const double _b=0.0);
	~Complex();
	Complex operator+(const Complex& x);
	Complex operator-(const Complex& x);
	Complex operator*(const Complex& x);
	friend Complex operator*(const double z, const Complex& x);
	Complex operator~();
	friend std::ostream& operator<<(std::ostream& os,const Complex& x);
	friend bool operator>>(std::istream& is, Complex& x);
};

#endif // !complex0_H_

