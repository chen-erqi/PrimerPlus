#ifndef Golf_H_
#define Golf_H_

class golf {
private:
	std::string Name;
	int handicap;
public:
	golf();
	golf(const std::string& _Name, int _handicap);
	void setgolf();
	int setgolf() const;
	void sethandicap(const int hc);
	void showgolf() const;
};

#endif // !Golf_H_

