#include<bits\stdc++.h>
using namespace std;


//快个锤子

int main()
{
	srand(unsigned(time(0)));
	vector<int> vi0;
	for (int i = 0; i < 1000000; i++)
		vi0.emplace_back(rand());
	vector<int>::iterator it = vi0.begin();
	vector<int> vi(vi0);
	list<int> li(vi0.size());
	for (list<int>::iterator list_it = li.begin(); list_it != li.end(); list_it++)
	{
		*list_it = *it;
		it++;
	}

	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	cout << "Sort of vector: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	li.sort();//list的sort是内置的！！！
	end = clock();
	cout << "Sort of List: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	it = vi0.begin();
	for (list<int>::iterator list_it = li.begin(); list_it != li.end(); list_it++)
	{
		*list_it = *it;
		it++;
	}

	start = clock();
	it = vi.begin();
	for (list<int>::iterator list_it = li.begin(); list_it != li.end(); list_it++)
	{
		*it = *list_it;
		it++;
	}
	sort(vi.begin(), vi.end());
	it = vi.begin();
	for (list<int>::iterator list_it = li.begin(); list_it != li.end(); list_it++)
	{
		*list_it = *it;
		it++;
	}
	end = clock();
	cout << "Sort of copy: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	
	system("pause");
	return 0;
}