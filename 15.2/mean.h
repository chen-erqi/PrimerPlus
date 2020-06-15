#ifndef mean_H_
#define mean_H_
#include<stdexcept>
#include<string>
using std::logic_error;
using std::string;

//mesg是自己定义的
//what是派生的 用构造函数的中的s去构造logic_error!

class bad_hmean :public logic_error
{
private:
	string name;
public:
	explicit bad_hmean(const string& n="hmean", const string& s = "Error in hmean()\n");
	string mesg();
	virtual ~bad_hmean(){}  //析构函数不推荐抛出异常 应该把异常封装在析构函数中
};

bad_hmean::bad_hmean(const string& n,const string& s):name(n),logic_error(s){}

inline string bad_hmean::mesg()
{
	return "hmean() arguments a=-b should be div a+b=0!\n";
}



class bad_gmean :public logic_error
{
private:
	string name;
public:
	explicit bad_gmean(const string& n = "gmean", const string& s = "Error in gmean()\n");
	string mesg();
	virtual ~bad_gmean(){}
};

bad_gmean::bad_gmean(const string& n,const string& s):name(n),logic_error(s){}

inline string bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

#endif // !mean_H_

