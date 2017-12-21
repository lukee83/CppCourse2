#include <iostream>
//#include <string>
//#include <vector>

using namespace std;

// 1 
constexpr long double operator"" deg(long double d)
{
	return d * 3.1415 / 180;
}

void operator"" _print(const char *str)
{
	cout << str << endl;
}

void operator"" _print(const char *str, std::size_t size)
{
	cout << str << endl;
}

// 2 enum classes; 
enum {almafa, kortefa, szilvafa};               // comiler error if: "int almafa;" in main
enum class Color : int {black, red, green};     // 0, 1, 2 still ok
enum class ColorC : char { black, red, green }; // in chars

// 3



int main()
{
	/*
	// 1
	cout << 90.0deg << endl;
	0x123456_print;
	"almafa"_print;

	// 2
	//int almafa;
	Color::black; // ok
	Color a = Color::black;
	
	// 3
	float f = 0;
	int   j = 0;
	
	for (int i = 0; i < 100000000; ++i)
	{
		j++;
		f += 1.0f;
	}

	cout << "float: " << f << endl;
	cout << "int  : " << j << endl;
	cout << "xxxxx: " << static_cast<float>(100000000) << endl;
	*/
	// 4




	system("pause");

	return 0;
}