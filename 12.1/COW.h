#ifndef COW_H_
#define COW_H_

class Cow {
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow() const; //display all cow data.
};

#endif // !COW_H_

