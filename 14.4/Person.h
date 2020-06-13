#ifndef Person_H_
#define Person_H_
#include<string>

using std::string;

//既然设置了Set作为接口进行组件相互交叉设置
//在类内部 Get应该作为私有函数 作为Get_(class name)进行定义！

class Person 
{
private:
	string FirstName;
	string LastName;
protected:							//保护成员 派生类可以直接访问基类中的protect成员
	virtual void Data() const;		//虚基类的保护成员只可以传递到下一代继承，避免了继承冲突
	virtual void Get();
public:
	Person():FirstName("NULL"),LastName("NULL"){}
	Person(const string& _FirstName, const string& _LastName) :FirstName(_FirstName),LastName(_LastName){}
	Person(const Person& p);
	virtual ~Person() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;	//抽象基类  纯虚函数 可以不实现 只声明
};

class Gunslinger :virtual public Person
{
private:
	int num;
protected:							//保护成员 派生类可以直接访问基类中的protect成员
	void Data() const;				//把函数作为保护成员
	void Get();
public:
	Gunslinger() :num(0), Person() {};
	Gunslinger(int _num, const string& _FirstName, const string& _LastName) :Person(_FirstName, _LastName),num(_num){}
	Gunslinger(int _num, const Person& p):num(_num),Person(p){}
	double Draw() const;
	void Show() const;
	void Set();						//把Set留作接口 直接调用成员内部的Get
};

class PokerPlayer :virtual public Person
{
protected:
	void Data() const;
public:
	PokerPlayer():Person(){}
	PokerPlayer(const string& _FirstName,const string& _LastName):Person(_FirstName,_LastName){}
	PokerPlayer(const Person& p):Person(p){}
	int Draw() const;
	void Show() const;
	void Set();
};

class BadDude :public PokerPlayer, public Gunslinger
{
protected:
	void Data() const;
	void Get();
public:
	BadDude(){}
	BadDude(int n, const string& _First, const string& _Last) :Person(_First, _Last), Gunslinger(n, _First, _Last), PokerPlayer(_First, _Last){}
	BadDude(int n,const Person& p):Person(p),Gunslinger(n,p),PokerPlayer(p){}
	BadDude(const Gunslinger& g):Person(g),Gunslinger(g),PokerPlayer(g){}
	BadDude(int n,const PokerPlayer& Pp):Person(Pp),Gunslinger(n,Pp),PokerPlayer(Pp){}
	double Gdraw() const;
	int Cdraw() const;
	void Set();
	void Show() const;
};


#endif // !Person_H_