#include<bits\stdc++.h>
using namespace std;
#include"QueueTp.h"
#include<windows.h>



int main()
{
	Queue<Worker*> q(5);
	Worker* temp;
	for (int i = 0; i < 5; i++)
	{
		char ch;
		cout << "Enter the command: \n";
		cout << "A to EnQueue,\n";
		cout << "P to DeQueue, \n";
		cout << "Q to quit.\n";

		HANDLE hout;
		COORD cursorPos;
		CONSOLE_SCREEN_BUFFER_INFO blnfo;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hout, &blnfo);
		cursorPos.X = strlen("Enter the command: ");
		cursorPos.Y = blnfo.dwCursorPosition.Y - 4;
		SetConsoleCursorPosition(hout, cursorPos);

		cin >> ch; cin.get();
		cursorPos = blnfo.dwCursorPosition;
		SetConsoleCursorPosition(hout, cursorPos);

		while (!strchr("APQ", ch))
		{
			cout << "Please Enter a A/P/Q: ";
			cin >> ch;
		}

		if (ch == 'Q')
			break;
		switch (ch)
		{
		case'A':
			temp = new Worker;
			temp->Set();
			if (q.isfull())
				cout << "Queue is full!\n";
			else
				q.enQueue(temp);
			break;
		case'P':
			if (q.isempty())
				cout << "Queue is empty!\n";
			else
				q.dequeue(temp);
			break;
		}
	}
	cout << "\nHere are the total count: " << q.queueCount() << endl;
	
	while (!q.isempty())
	{
		Worker* temp = new Worker;
		q.dequeue(temp);
		temp->Show();
		delete temp;
	}
	cout << "Done!\n";





	system("pause");
	return 0;
}



