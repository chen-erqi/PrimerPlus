#ifndef SALES_H_
#define SALES_H_

class Sales{
private:
	static const int QUARTERS = 4;
	double sales[QUARTERS];
	double maxVal;
	double minVal;
	double average;
public:
	Sales();
	Sales(const double ar[]);
	void setSales();
	void showSales() const;
};

#endif // !SALES_H_

