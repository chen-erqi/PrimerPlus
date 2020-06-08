#ifndef vec_H_
#define vec_H_
#include<iostream>

namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	//RECT for rectangular,POL for Polar modes
	private:
		double x;
		double y;
		Mode mode;
	//private methods for setting value
		//void set_mag();
		//void set_ang();
		void set_x(double n1,double n2);
		void set_y(double n1,double n2);
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const;              //report magnitude
		double angval()const;              //report angle
		void polar_mode();//set mode to POL
		void rect_mode();//set mode to RECT
	//operator overloading
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
	//friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}

#endif // !vec_H_
