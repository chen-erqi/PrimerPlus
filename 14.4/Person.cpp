#include<bits\stdc++.h>
#include"Person.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Person::~Person(){}

void Person::Data() const
{
	cout << "First Name: " << FirstName << endl;
	cout << "Lats Name: " << LastName << endl;
}

void Person::Get()
{
	cout << "Enter First Name: ";
	getline(cin, FirstName);
	cout << "Enter Last Name: ";
	getline(cin, LastName);
}

void Person::Show() const
{
	Data();
}

void Person::Set()
{
	Get();
}

void Gunslinger::Data() const
{
	cout << "Scar Num: " << num << endl;
	cout << "Draw time: " << Draw() << endl;
}

void Gunslinger::Get()
{
	cout << "Enter Scar Num: ";
	cin >> num;
}

void Gunslinger::Set()
{
	cout << "Enter Gunslinger's name: \n";
	Person::Get();
	Get();
}

void Gunslinger::Show() const
{
	cout << "The Gunslinger: " << endl;
	Person::Data();
	Data();
}

double Gunslinger::Draw() const
{
	srand(time(0));
	return double(rand() % 3 + 1);
}

void PokerPlayer::Set()
{
	cout << "Enter the Poker's name: \n";
	Person::Get();
}

int PokerPlayer::Draw() const
{
	srand(time(0));
	return rand() % 52 + 1;
}

void PokerPlayer::Data() const
{
	cout << "The cards: " << Draw() << endl;
}

void PokerPlayer::Show() const
{
	cout << "The Poker: " << endl;
	Person::Data();
	Data();
}

double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
	cout << "The next cards: " << Cdraw() << endl;
	cout << "The Draw Time: " << Gdraw() << endl;
}

void BadDude::Get()
{
	Gunslinger::Get();
}

void BadDude::Set()
{
	cout << "The BadDude's name: \n";
	Person::Get();
	Get();
}

void BadDude::Show() const
{
	cout << "BadDude: \n";
	Person::Data();
	Data();
}