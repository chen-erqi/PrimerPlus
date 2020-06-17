#include<bits\stdc++.h>
using namespace std;



vector<int> Lotto(int n, int num);
int main()
{
	vector<int> winner = Lotto(51, 6);
	for (int x : winner)
		cout << x << endl;
	

	
	system("pause");
	return 0;
}

vector<int> Lotto(int n, int num)
{
	vector<int> res;
	for (int i = 1; i <= n; i++)
		res.emplace_back(i);
	random_shuffle(res.begin(), res.end());
	return vector<int>(res.begin(), res.begin() + num);
}