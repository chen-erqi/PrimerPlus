#ifndef Plorg_H_
#define Plorg_H_

class Plorg {
private:
	std::string Name;
	int CI;
public:
	Plorg(const std::string& _Name="Plorga", int _CI=50);
	void SetPlorg();
	void showPlorg() const;
	void modifyCI(int _CI);
};

#endif // !Plorg_H_

