#include<bits\stdc++.h>
using namespace std;





void ShowStr(const string& s)
{
	cout << s << endl;
}

void GetStrs(ifstream& fin, vector<string>& v)
{
	char* s;
	size_t len;
	while (fin.read((char*)&len, sizeof(size_t)))
	{
		s = new char[len];
		fin.read(s, len);
		s[len + 1] = '\0';
		v.emplace_back(s);
	}
}

class Store
{
private:
	ofstream& fout;
public:
	Store(ofstream& os) :fout(os) {}
	void operator()(const string& s)
	{
		size_t len = s.size();
		fout.write((char*)&len, sizeof(size_t));
		fout.write(s.data(), len);
	}
};

int main()
{
	vector<string> vostr;
	string temp;

	cout << "Enter strings(empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.emplace_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("Strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	




	system("pause");
	return 0;
}