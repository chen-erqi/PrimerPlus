#include<bits\stdc++.h>
using namespace std;




int main(int argc,char* argv[])
{
	if(argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	fin.open(argv[1], ios_base::in);
	if (!fin.is_open())
	{
		cerr << "Could not open " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	
	ofstream fout(argv[2], ios_base::out | ios_base::trunc);
	if (!fout.is_open())
	{
		cerr << "Could not open " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Here are the current contents of the " << argv[1] << " file: \n";
	string s;
	fin >> s;
	fout << s;
	cout << s << endl;

	fin.close();
	fout.close();
	


	system("pause");
	return 0;
}