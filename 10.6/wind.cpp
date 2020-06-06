#include<bits\stdc++.h>
using namespace std;
#include"Move.h"

int main()
{
	Move dir1{ 2.0,3.0 };
	Move dir2{ 3.0,4.0 };

	dir1.showMove();
	dir1.add(dir2).showMove();
	dir1.reset(2.0, 3.0);
	dir1.showMove();
	

	system("pause");
	return 0;
}