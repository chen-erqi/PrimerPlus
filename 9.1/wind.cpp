#include<bits\stdc++.h>
using namespace std;
#include"golf.h"


int main()
{
	golf person[2]; 
	int per_idx = 0;
	while (per_idx != 2 && setgolf(person[per_idx++]));
	for (golf x : person)
		showgolf(x);

	system("pause");
	return 0;
}