#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	/*map<int, string> m;

	m[0] = "almafa";
	m[1] = "kortefa";

	for (auto&[k, v] : m)
	{
		//v += "_" + to_string(k);
		cout << k << v << endl;
	}

	for (const auto[k, v] : m)
	{
		cout << k << v << endl;
	}*/

	vector<string> words;

	while(true)
	{
		string s;
		getline(cin, s);

		if (!s.empty())
			words.push_back(s);
		else
			break;
	}

	cout << "items in vector: " << endl;

	for(int i = 0 ; i<words.size(); ++i)
	{
		cout << words[i] << endl;
	}

	cout  << endl;

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "items in vector: " << endl;

	for ( auto &item : words)
	{
		item = "aa";
		cout << item << endl;
	}


	system("pause");

	return 0;
}


