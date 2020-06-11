#ifndef Nana_H_
#define Nana_H_
#include<iostream>
#include<string>

class ABC {
private:
	char* fullname;
	int level;
public:
	ABC(const char* f = "null", int lv = 0);
	ABC(const ABC& ab);
	ABC& operator=(const ABC& ab);
	virtual ~ABC();
	virtual void View() const = 0;			//指出是一个抽象基类
};

class baseDMA :public ABC {
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0, const char* f = "null", int lv = 0);
	baseDMA(const baseDMA& rs);
	~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	virtual void View() const;
};

class lacksDMA :public ABC {
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* f = "null", int lv = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	~lacksDMA() {};
	virtual void View() const;
};

class hasDMA :public ABC {
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* f = "null", int lv = 0);
	hasDMA(const char* s, const ABC& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	virtual void View() const;
};

#endif // !Nana_H_

