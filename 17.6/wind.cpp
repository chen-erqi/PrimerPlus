#include<bits\stdc++.h>
using namespace std;
#include"emp.h"
#include<windows.h>


//要正确理解题意啊！！！！

const int MAX = 10;
const char* file = "Asu.txt";
int main()
{
	abstr_emp* pc[MAX];
	ifstream fin;
	int classtype;
	int i = 0;
	char ch;
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the current contens of the " << file << " file:\n";
		while ((fin >> classtype).get(ch))//一开始文件为空 读取失败！ 第二次有文件了读取才能成功
		{
			switch (classtype)
			{
			case classtype::Employee:
				pc[i] = new employee;
				break;
			case classtype::Fink:
				pc[i] = new fink;
				break;
			case classtype::HighFink:
				pc[i] = new highfink;
				break;
			case classtype::Manager:
				pc[i] = new manager;
				break;
			default:break;
			}
			cout << classtype << endl;
			pc[i]->getall(fin);
			pc[i]->ShowAll();
			i++;
			if (i >= MAX)
				break;
		}
	}
	fin.close();

	ofstream fout;
	fout.open(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "e to employee\tm to manager\n";
	cout << "f to fink\th to highfink\n";
	cout << "other to quit: ";
	int index = i;
	while (cin.get(ch).get() && ch != 'q' && index < MAX)
	{
		switch (ch)
		{
		case 'e':
			pc[index] = new employee;
			pc[index]->SetAll();
			pc[index]->writeall(fout);
			index++;
			break;
		case 'm':
			pc[index] = new manager;
			pc[index]->SetAll();
			pc[index]->writeall(fout);
			index++;
			break;
		case 'f':
			pc[index] = new fink;
			pc[index]->SetAll();
			pc[index]->writeall(fout);
			index++;
			break;
		case 'h':
			pc[index] = new highfink;
			pc[index]->SetAll();
			pc[index]->writeall(fout);
			index++;
			break;
		default:
			break;
		}
		if (index > MAX)
			break;
		cout << "Try again: ";
	}
	fout.close();
	for (int i = 0; i < index; i++)
		pc[i]->ShowAll();




	system("pause");
	return 0;
}