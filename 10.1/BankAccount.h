#ifndef BankAccount_H_
#define BankAccount_H_

class BankAccount
{
private:
	std::string Name;
	std::string AccountNum;
	double balance;
public:
	BankAccount(const std::string& _Name, const std::string& _AccountNum, double balance = 0.0);
	void show() const;
	void push(const double cash);
	void take(const double cash);
};


#endif // !BankAccount_H_

