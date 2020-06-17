#include<bits\stdc++.h>
using namespace std;

string Name;
void GenFile()
{
	ofstream fin;
	Name = "nanase.txt";
	fin.open(Name);
	string letter;
	cout << "Please Enter 4 letters!" << endl;
	int cnt = 4;
	while (cnt--&&getline(cin, letter))
	{
		fin << letter << endl;
	}
	fin.close();
}
void FillWord(vector<string>& v)
{
	ifstream fin;
	string letter;
	fin.open(Name);
	if (!fin.is_open())
	{
		cerr << "Can't Open " << Name << endl;//cerr 输出到标准错误的ostream 在紧急情况还能输出信息！
		exit(EXIT_FAILURE);
	}
	while (fin)
	{
		fin >> letter;
		v.emplace_back(letter);
	}
	fin.close();
}
int main()
{
	GenFile();
	char play;
	srand(unsigned(time(0)));
	cout << "Will you play a word game? <y/n>: ";
	cin >> play;
	play = tolower(play);

	vector<string> v;
	FillWord(v);

	while (play == 'y')
	{
		string target = v[rand() % v.size()];
		int length = target.size();
		string attempt(length, '-');
		string bad_chars;
		int guesses = 6;
		cout << "Guess my secret Word.It has " << length << " letters, and you guess\n";
		cout << "one letter at a time.You get " << guesses << " worng guesses.\n";
		cout << "Your word: " << attempt << endl;

		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (bad_chars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh,bad guess!\n";
				--guesses;
				bad_chars += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			cout << "Your Word: " << attempt << endl;
			if (attempt != target)
			{
				if (bad_chars.size() > 0)
					cout << "Bad choices: " << bad_chars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n>: ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye!\n";
	remove(Name.c_str());
	

	
	system("pause");
	return 0;
}