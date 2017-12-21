#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <optional>
#include <variant>
//#include <numeric>
//#include <algorithm>
//#include <functional>
//#include <memory> // smart ptrs

using namespace std;

struct Almafa
{
	char ch;
	int i;
	double d;
};

union Kortefa
{
	char ch;
	int i;
	double d;
};


optional<string> bp(bool b)
{
	if (b)
		return "Godzilla";
	
	return {};
}

int main()
{
	cout << bp(true).value_or("default_value") << endl;
	cout << bp(false).value_or("default_value") << endl;

	if (auto str = bp(true); str.has_value())
	{
		cout << str.value() << endl;
	}
	
	cout << "--------------------" << endl;

	variant<int, double> v, w;
	v = 12;

	int i = std::get<int>(v);
	cout << i << endl;

	try{
		double d = std::get<double>(v);
	}
	catch (bad_variant_access& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "--------------------" << endl;

	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(char): " << sizeof(char) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(Almafa): " << sizeof(Almafa) << endl;
	cout << "sizeof(Kortefa): " << sizeof(Kortefa) << endl;
	cout << "alignof(Almafa): " << alignof(Almafa) << endl;


	system("pause");

	return 0;
}