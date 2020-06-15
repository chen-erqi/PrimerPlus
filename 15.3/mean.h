#ifndef mean_H_
#define mean_H_
#include<string>
#include<stdexcept>
using std::logic_error;
using std::cout;
using std::endl;

class _error :public logic_error
{
private:
	double v1;
	double v2;
	//std::string s;
public:
	explicit _error(double _v1=0.0,double _v2=0.0,const std::string& _s="Error!\n"):v1(_v1),v2(_v2),logic_error(_s){}
	virtual void mesg() = 0;//抽象基类 可暂时不实现
	virtual ~_error(){}
};

class bad_hmean :public _error
{
private:
	double a;
	double b;
public:
	explicit bad_hmean(double _a = 0.0, double _b = 0.0) :a(_a), b(_b), _error(_a, _b, "Error in hmean()!\n"){}
	void mesg();
};

class bad_gmean :public _error
{
private:
	double a;
	double b;
public:
	explicit bad_gmean(double _a = 0.0, double _b = 0.0) :a(_a), b(_b), _error(_a, _b, "Error in gmean()!\n") {}
	void mesg();
};

inline void bad_hmean::mesg()
{
	cout << "hmean() arguments a=-b should be div a+b=0!\n";
	cout << "X = " << a << ", and Y is " << b << endl;
}

inline void bad_gmean::mesg()
{
	cout << "gmean() arguments should be >= 0\n";
	cout << "X is " << a << ", and Y is " << b << endl;
}



#endif // !mean_H_

