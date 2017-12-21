#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;

	m[0] = "almafa";
	m[1] = "kortefa";

	for (auto& [k, v] : m)
	{
		//v += "_" + to_string(k);
		cout << k << v << endl;
	}

	for (const auto[k, v] : m)
	{
		cout << k << v << endl;
	}

	//system("pause");

    return 0;
}

