#ifndef string2_H_
#define string2_H_
#include<iostream>

class String {
private:
	char* str;  
	int len;
	static int num_string;
public:
	String(const char* s);
	String();
	String(const String& s);
	~String();
	int length() const;

	String& operator=(const String& s);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	void stringup();
	void stringlow();
	int has(char x) const;

	friend bool operator<(const String& s1, const String& s2);
	friend bool operator>(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
	friend String operator+(const String& s1, const String& s2);
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);

	static int HowMany();
};

#endif // !string2_H_

