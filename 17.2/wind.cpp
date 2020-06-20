#include<bits\stdc++.h>
using namespace std;




int main(int argc,char* argv[])
{
	if(argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout(argv[1], ios_base::out | ios::app);//app 在文件后面插入
	if (!fout.is_open())
	{
		cerr << "Can't open " << argv[1] << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter a string: \n";
	string s;
	getline(cin, s);
	fout << s << endl;
	fout.close();
	


	system("pause");
	return 0;
}