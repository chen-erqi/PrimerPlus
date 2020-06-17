#include<bits\stdc++.h>
using namespace std;




int main()
{
	vector<string> Mat;
	vector<string> Pat;
	string Name;
	cout << "Enter Mat's friend <q to quit> : " << endl;
	while (cin >> Name && Name != "q")
		Mat.emplace_back(Name);
	sort(Mat.begin(), Mat.end());
	cout << "Mat's friend:";
	for (string x : Mat)
		cout << " " << x;
	cout << "\nEnter Pat's friend <q to quit> : " << endl;
	while (cin >> Name && Name != "q")
		Pat.emplace_back(Name);
	sort(Pat.begin(), Pat.end());
	cout << "Pat's friend:";
	for (string x : Pat)
		cout << " " << x;
	cout << endl;
	
	vector<string> res;
	int i, j;
	for ( i = 0, j = 0; i < Mat.size() && j < Pat.size();)
	{
		if (Mat[i] < Pat[j])
		{
			res.emplace_back(Mat[i]);
			i++;
		}
		else if (Mat[i] > Pat[j])
		{
			res.emplace_back(Pat[j]);
			j++;
		}
		else
			j++;
	}
	while (i < Mat.size())
		res.emplace_back(Mat[i++]);
	while (j < Pat.size())
		res.emplace_back(Pat[j++]);

	cout << "The whole array of friend:";
	for (string x : res)
		cout << " " << x;
	cout << endl;



	
	system("pause");
	return 0;
}