#include<bits\stdc++.h>
using namespace std;
#include"emp.h"
#include<windows.h>



const int MAX = 10;
const char* file = "Nana.txt";
int main(int argc,char* argv[])
{
	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout;
	for (int file = 1; file < argc; file++)
	{
		fout.open(argv[file]);
		cout << "Which ClassType do you want to Enter <5 to quit>: ";
		HANDLE hout;
		COORD cursorPos1, cursorPos2;
		CONSOLE_SCREEN_BUFFER_INFO blnfo1, blnfo2;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hout, &blnfo1);
		cursorPos1 = blnfo1.dwCursorPosition;
		cout << endl;
		cout << "0 Employee\t1 Manager\n";
		cout << "2 Fink\t3 HighFink\n";
		GetConsoleScreenBufferInfo(hout, &blnfo2);
		cursorPos2 = blnfo2.dwCursorPosition;
		SetConsoleCursorPosition(hout, cursorPos1);
		int classtype;
		cin >> classtype;
		cin.get();
		SetConsoleCursorPosition(hout, cursorPos2);

		while (classtype>=0&&classtype<=3)
		{
			switch (classtype)
			{
			case classtype::Employee:
			{
				employee a;
				a.SetAll();
				a.writeall(fout);
				break;
			}
			case classtype::Fink:
			{
				fink a;
				a.SetAll();
				a.writeall(fout);
				break;
			}
			case classtype::HighFink:
			{
				highfink a;
				a.SetAll();
				a.writeall(fout);
				break;
			}
			case classtype::Manager:
			{
				manager a;
				a.SetAll();
				a.writeall(fout);
				break;
			}
			default:break;
			}
			cout << "Enter the new classtype: ";
			if (!isdigit(cin.peek()))
				exit(EXIT_FAILURE);//·ÀÊÖ¼ú
			cin >> classtype;
			cin.get();
		}
	}



	system("pause");
	return 0;
}