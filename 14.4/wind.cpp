#include<bits\stdc++.h>
using namespace std;
#include"Person.h"
#include<windows.h>


int main()
{
	Person* p[5];
	int ct;
	for (ct = 0; ct < 5; ct++)
	{
		char choice;
		cout << "Enter the Person: \n";
		cout << "g: Gunslinger\tp: PokePlayer \n";
		cout << "b: BadDude\tq: quit\n";

		//将光标设在Enter the Person: 处！
		HANDLE hStdout;
		COORD cursorPos;
		
		CONSOLE_SCREEN_BUFFER_INFO blnfo;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout, &blnfo);			//获取当前光标位置
		cursorPos.X = strlen("Enter the Person: ");			//获取上一行的内容长度,作为X坐标
		cursorPos.Y = blnfo.dwCursorPosition.Y - 3;			//设置后续输出的Y坐标
		SetConsoleCursorPosition(hStdout, cursorPos);		//光标定位


		cin >> choice;

		//光标回到原处
		cursorPos = blnfo.dwCursorPosition;					
		SetConsoleCursorPosition(hStdout, cursorPos);


		while (!strchr("gpbq", choice))
		{
			cout << "Please Enter as p/g/b/q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;

		switch (choice)
		{
		case'p':
			p[ct] = new PokerPlayer;
			break;
		case'b':
			p[ct] = new BadDude;
			break;
		case'g':
			p[ct] = new Gunslinger;
			break;
		}
		cin.get();
		p[ct]->Set();
	}


	//没有设置动态数组长度 输入长度必须为5 不然会发生错误 
	cout << "\nHere is your men: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		p[i]->Show();
	}
	for (int i = 0; i < 5; i++)
		delete p[i];
	cout << "Bye\n";



	system("pause");
	return 0;
}



