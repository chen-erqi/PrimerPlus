#ifndef wine_H_
#define wine_H_
#include<string>
#include<valarray>
#include<iostream>
#include<utility>

//NOTICE:注意using std 需要的类！！！！！
using std::pair;
using std::string;
using std::ostream;
using std::valarray;

typedef pair<valarray<int>, valarray<int>> PAA;
typedef valarray<int> VI;

class wine :private pair<valarray<int>,valarray<int>>, private string
{ 
private:
	int years;
public:
	wine(const char* l, int y, const int yr[], const int bot[]);
	wine(string& l, int y, PAA v);
	wine(const char* l, int y);
	virtual ~wine();
	string& Label();	//引用 函数末端不能用const 不然应该是const string&
	int sum() const;
	void getBottles();
	void show() const;
};

#endif // !wine_H_

