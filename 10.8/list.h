#ifndef list_H_
#define list_H_

typedef int Item;

class myList {
private:
	static const int LIMIT = 5;
	Item items[LIMIT];
	int top;
public:
	myList() { top = 0; }
	bool push(const Item);
	bool empty() const;
	bool full() const;
	void visit(void(*pf)(Item& m));//显示某个数据项 根据指针指向的函数决定执行哪种函数
};

#endif // !list_H_

