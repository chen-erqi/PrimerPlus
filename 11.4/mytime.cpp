#include<bits\stdc++.h>
#include"mytime.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& t1,const Time& t2)
{
	return Time((t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60), (t1.minutes + t2.minutes) % 60);
}

Time operator-(const Time& t1, const Time& t2)
{
	return Time((t1.minutes + 60 * t1.hours - t2.minutes - 60 * t2.hours) / 60, (t1.minutes + 60 * t1.hours - t2.minutes - 60 * t2.hours) % 60);
}

Time operator*(double mult, const Time& t)
{
	long totalMin = t.hours * mult * 60 + t.minutes * mult;
	return Time(totalMin / 60, totalMin % 60);
}

Time operator*(const Time& t, double mult)
{
	return mult * t;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}