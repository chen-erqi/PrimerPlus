#include<bits\stdc++.h>
#include"vec.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
	//compute degrees in one radian
	const double Rad_to_deg = 45.0 / atan(1.0);

	//private methods


	//set x from polar coordinate
	void Vector::set_x(double n1,double n2)
	{
		x = n1 * cos(n2);
	}

	//set y from polar coordinate
	void Vector::set_y(double n1,double n2)
	{
		y = n1 * sin(n2);
	}

//public methods
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			set_x(n1, n2);
			set_y(n1, n2);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	double Vector::magval() const
	{
		return sqrt(x * x + y * y);
	}

	double Vector::angval() const
	{
		if (x == 0.0 && y == 0.0)
			return 0.0;
		else
			return atan2(y, x);
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			set_x(n1,n2);
			set_y(n1,n2);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector(){}

	void Vector::rect_mode()
	{
		mode = RECT;
	}
	void Vector::polar_mode()
	{
		mode = POL;
	}

	//operator overloading
	//add two Vectors
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	//subtract Vector b from a
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	//reverse sign of Vector
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	//multiply vector by n
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	//friend 
	//multiply n by Vector a
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	//display rect coordinate if mode is RECT
	//display polar coordinate if mode is POL
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "( x,y ) = ( " << v.x << "," << v.y << " )";
		else if (v.mode == Vector::POL)
		{
			os << "( m,a ) = ( " << v.magval()<< "," << v.angval() << " )";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}//end Namespace VECTOR