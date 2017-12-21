#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

tuple<int, int, string> testNes()
{
	return make_tuple(3, 3, "almafa");
}


int main()
{
	map<string, int> m1;

	m1["alma"] = 70;
	m1["szilva"] = 80;
	m1["meggy"] = 55;

	for (auto x : m1)
	{
		cout << x.first << ": " << x.second << endl;
	}

	unordered_map<string, int> m2;

	m2["alma"] = 70;
	m2["szilva"] = 80;
	m2["meggy"] = 55;

	for (auto x : m2)
	{
		cout << x.first << ": " << x.second << endl;
	}


	for (auto [k, v]  : m2)
	{
		cout << k << ": " << v << endl;
	}

	//tuple c++17
	//auto&&[a1, a2, a3] = testNes();  &&-t én raktam bele
	[[maybe_unused]] auto[a1, a2, a3] = testNes();
	cout << a1 << ", " /*<< a2*/ << ", " << a3 << endl;

	//tie c++11-14 ?
	int b1, b2;
	string b3;

	//tie(b1, b2, b3) = testNes();
	//cout << b1 << ", " << b2 << ", " << b3 << endl;
	tie(b1, std::ignore, b3) = testNes();
	cout << b1 << ", " << ", " << b3 << endl;

	system("pause");

	return 0;
}