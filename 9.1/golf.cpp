#include"golf.h"
#include<bits\stdc++.h>
using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	char name[Len];
	int hc;
	cout << "Please Enter player's name:";
	if (cin.getline(name, Len) && strlen(name))
	{
		cout << "Please enter player's level:";
		cin >> hc;
		cin.get();
		setgolf(g, name, hc);
		return 1;
	}
	else
		return 0;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	cout<<endl;
	cout << "The current player's name: " << g.fullname << endl;
	cout << "The current player's level: " << g.handicap << endl;
}