#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <array>
#include <vector>
#include <functional>

using namespace std;

auto fun1(int i, int j)->int
{
	return i + j + 3;
}

template<typename T1, typename T2>auto fun2(T1 i, T2 j)->decltype(T1+T2)
{
	return i + j;
}

int main()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	int j = 1;

	for_each(v.begin(), v.end(), 
		[&/*for global variables*/](int i)/*-> void*/ { cout << i+j <<", "; }
	);
	cout << endl;
	std::array<int, 5> a {2, 4, 6, 5, 0};

	int d = 3;
	auto it = find_if(a.begin(), a.end(), [=, &d](int i)-> bool {return !(i % d); });
	//cout << *it << endl;

	// functional fejallomany

	auto f = [](int i, int j) {return i + j; };

	//ezz-e fog kiertekelodni
	std::function<int(int, int)> f2 = [](int i, int j) {return i + j; };

	cout << f(2,2) << endl;
	cout << [](int i, int j) {return 2 * i*j; }(2, 3) << endl;

	cout << endl;

	vector<string> vs;

	while (1)
	{
		string s;
		getline(std::cin, s);
		if (s.empty()) break;
		//vs.push_back(s);
		vs.push_back(std::move(s));
	}

	//sort(vs.begin(), vs.end()); irjuk meg!

	sort(vs.begin(), vs.end(), 
		[](const string& s1, const string& s2) 
			{
				return  s1[s1.length()-1] < s2[s2.length()-1] || (s1[s1.length() - 1] == s2[s2.length() - 1] && s1 < s2);
			}
		);

	for (const auto& x : vs) cout << x << endl;

	system("pause");

	return 0;
}