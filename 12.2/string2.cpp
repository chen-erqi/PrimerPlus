#include<bits\stdc++.h>
#include"string2.h"
using std::cout;
using std::cin;
using std::endl;

int String::num_string = 0;
int String::HowMany() { return num_string; }

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_string++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_string++;
}

String::String(const String& s)
{
	num_string++;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
}

String::~String() { --num_string; delete[] str; }

String& String::operator=(const String& s)
{
	if (this == &s)
		return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
	}
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
	}
}

int String::has(char x) const
{
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == x)
			cnt++;
	return cnt;
}

char& String::operator[](int i) { return str[i]; }              //read-write
const char& String::operator[](int i) const { return str[i]; }  //only read

bool operator<(const String& s1, const String& s2) { return strcmp(s1.str, s2.str) < 0; }
bool operator>(const String& s1, const String& s2) { return s2 < s1; }
bool operator==(const String& s1, const String& s2) { return strcmp(s1.str, s2.str) == 0; }

String operator+(const String& s1, const String& s2)
{
	String res;
	res.len = s1.len + s2.len + 2;
	delete[] res.str;
	res.str = new char[res.len];
	sprintf_s(res.str, res.len ,"%s%s", s1.str, s2.str);
	return res;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	char temp[80];
	is.get(temp, 80);
	if (is)
		s = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}