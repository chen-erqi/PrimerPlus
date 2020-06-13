#ifndef emp_H_
#define emp_H_
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;
using std::ostream;

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp() :fname("NULL"), lname("NULL"), job("NULL"){}
	abstr_emp(const string& fn, const string& ln, const string& j) :fname(fn), lname(ln), job(j){}
	virtual void ShowAll() const;
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;
};

class employee :public abstr_emp
{
public:
	employee() :abstr_emp(){}
	employee(const string& fn, const string& ln, const string& j) :abstr_emp(fn, ln, j){}
	virtual void ShowAll() const;
	virtual void SetAll();
};

class manager :virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int& InchargeOf() { return inchargeof; }
public:
	manager() :abstr_emp(), inchargeof(0){}
	manager(const string& fn, const string& ln, const string& j, int ico = 0) :abstr_emp(fn, ln, j), inchargeof(ico){}
	manager(const abstr_emp& e, int ico) :abstr_emp(e), inchargeof(ico){}
	manager(const manager& m) :abstr_emp(m), inchargeof(m.inchargeof){}
	virtual void ShowAll() const;
	virtual void SetAll();
};

class fink :virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink() :abstr_emp(), reportsto("NULL"){}
	fink(const string& fn, const string& ln, const string& j, const string& rep) :abstr_emp(fn, ln, j), reportsto(rep) {}
	fink(const abstr_emp& e, const string& rep) :abstr_emp(e), reportsto(rep) {}
	fink(const fink& e) :abstr_emp(e), reportsto(e.reportsto) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	void getRep() {
		cout << "Enter Reportsto: ";
		getline(cin, reportsto);
	}
};

class highfink :public manager, public fink
{
public:
	highfink() :abstr_emp(), manager(), fink(){}
	highfink(const string& fn, const string& ln, const string& j, const string& rep, int ico) :abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rep){}
	highfink(const abstr_emp& e, const string& rep, int ico) :abstr_emp(e), manager(e, ico), fink(e, rep){}
	highfink(const manager& m, const string& rep) :abstr_emp(m), manager(m), fink(m, rep){}
	highfink(const fink& f, int ico) :abstr_emp(f), manager(f, ico), fink(f){}
	highfink(const highfink& h) :abstr_emp(h), manager(h), fink(h){}
	virtual void ShowAll() const;
	virtual void SetAll();
};

#endif // !emp_H_

