#include <iostream>
#include <string>
#include <vector>
#include "any.h"

using namespace std;


template <typename T>
int vicces(const T& t)
{
	if constexpr(std::_Is_integer(T))
	{
		// ha integer, akkor benne lesz a forrasban ez a resz
		// pl variadic template-nel hasznaljuk
	}
	else
	{
		// egyebkent nem
	}

}


int main()
{
	{
		Any a(12), b(10.3) /*, c(std::string("almafa"))*/;
		a = std::string("korte");

		cout << *(a.get<std::string>()) << endl;
		// cout << (a.get<int>()) << endl;        // nullptr
	}


	vector<int> v(fact(7));
	
	if constexpr (fact(3) == 6)
	{
		cout << "x" << endl;
	}
	else
	{
		cout << "y" << endl;
	}

	system("pause");



	return 0;
}
