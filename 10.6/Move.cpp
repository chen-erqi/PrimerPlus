#include<bits\stdc++.h>
#include"Move.h"

Move::Move(double a, double b)
{
	this->x = a;
	this->y = b;
}

Move Move::add(const Move& m) const
{
	return Move(m.x + this->x, m.y + this->y);
}

void Move::showMove() const
{
	std::cout << std::endl;
	std::cout << "The current x is: " << this->x << std::endl;
	std::cout << "The current y is: " << this->y << std::endl;
}

void Move::reset(double a, double b)
{
	this->x = a;
	this->y = b;
}

Move::~Move(){}