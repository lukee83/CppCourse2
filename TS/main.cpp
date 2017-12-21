#include <iostream>
#include <numeric>
#include <experimental/generator>

using namespace std;

std::experimental::generator<int> gen2(int &param)
{
	// lazy evaluation (laza kiertekeles

	for (int i = 0; ; ++i)
	{
		if(i == 500)
		{
			param = 500;
		}
		co_yield i; // 'kvazi-return', de belepesi pont is lesz
	}
}

std::experimental::generator<int> gen()
{
	// lazy evaluation (laza kiertekeles

	for (int i = 0; ; ++i)
	{
		co_yield i; // 'kvazi-return', de belepesi pont is lesz
	}
}

std::experimental::generator<int> take_until(std::experimental::generator<int> &g, int sentinel)
{
	for (auto v : g)
	{
		if (v == sentinel) break;
		co_yield v;
	}
	
}


int main()
{
	cout << "Hello World!" << endl;

	int param = 0;

	// mintha tarolobol olvasnal
	/*for(auto x : gen2(param))
	{ 
		cout << x << endl;
		cout << "param: " << param << endl;
		if (x == 510) break;
	}

	for (auto x : gen())
	{
		cout << x << endl;
		if (x == 510) break;
	}*/

	auto g = gen();
	auto t = take_until(g, 10);

	auto r = std::accumulate(t.begin(), t.end(), 0);

	cout << r << endl;


	system("pause");
	return 0;
}