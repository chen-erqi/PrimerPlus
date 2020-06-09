#include<bits\stdc++.h>
using namespace std;
#include"COW.h"

int main()
{
	{
		Cow a;
		a.ShowCow();
		Cow b("Nanase", "Game", 80);
		b.ShowCow();
		Cow c("Auska", "dark", 80);
		c.ShowCow();
		a = c;
		a.ShowCow();
	}

	system("pause");
	return 0;
}