#ifndef Person_H_
#define Person_H_

class Person {
private:
	static const int LIMIT = 25;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = "Asuka", fname[0] = '\0'; }
	Person(const std::string& ln, const char* fn = "Heyyou");

	void show() const;       //first-last 
	void Formalshow() const; //last-first
};

#endif // !Person_H_

