#include<bits\stdc++.h>
using namespace std;


//太懒了就不写打不开的判断了
const char* file1 = "mat.dat";
const char* file2 = "pat.dat";
const char* file3 = "matnpat.dat";
int main()
{
	ofstream fout;
	ifstream fin;
	string s;
	set<string> Mat;
	set<string> Pat;

	//制造两个文件
	fout.open(file1);
	cout << "Enter Mat's friend <q to quit>: " << endl;
	while (getline(cin, s) && s != "q")
		fout << s << endl;
	fout.close();
	fout.open(file2);
	cout << "Enter Pat's friend <q to quit>: " << endl;
	while (getline(cin, s) && s != "q")
		fout << s << endl;
	fout.close();


	//读入两个文件
	fin.open(file1);
	while (!fin.eof())
	{
		getline(fin, s);
		Mat.insert(s);
	}
	cout << "Mat's friend: ";//不用换行 之前写入时最后一个名字带了一个换行符
	for (const string& x : Mat)
		cout << x << endl;
	fin.close();
	fin.open(file2);
	while (!fin.eof())
	{
		getline(fin, s);
		Pat.insert(s);
	}
	fin.close();
	cout << "Pat's friend: ";
	for (string x : Pat)
	{
		cout << x << endl;
		Mat.insert(x);
	}

	cout << "Mat and Pat's friend: ";
	for (string x : Mat)
	{
		cout << x << endl;
		fout << x << endl;
	}
	fout.close();




	system("pause");
	return 0;
}