#include<bits\stdc++.h>
using namespace std;


/*
	与有序链表合并类似
*/

int main()
{
	ifstream fin1("NANA.txt"), fin2("NISHINO.txt");
	ofstream fout("Asuka.txt",ios_base::out);
	if (!fin1.is_open() || !fin2.is_open())
	{
		cerr << "Can't open " << "NANA.txt or NISHINO.txt" << endl;
		exit(EXIT_FAILURE);
	}
	if (!fout.is_open())
	{
		cerr << "Can't open Asuka.txt" << endl;
		exit(EXIT_FAILURE);
	}

	string s1, s2;
	while (!fin1.eof() && !fin2.eof())
	{
		getline(fin1, s1);
		cout << "File1: " << s1 << endl;
		getline(fin2, s2);
		cout << "File2: " << s2 << endl;
		fout << s1 << " " << s2 << endl;
	}
	while(!fin1.eof())
	{
		getline(fin1, s1);
		cout << "More file1: " << s1 << endl;
		fout << s1 << endl;
	}
	while (!fin2.eof())
	{
		getline(fin2, s2);
		cout << "More file2: " << s2 << endl;
		fout << s2 << endl;
	}
	fin1.close();
	fin2.close();
	fout.close();


	system("pause");
	return 0;
}