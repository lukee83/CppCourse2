#include <iostream>
#include <string>
#include <type_traits>
#include <stdexcept>

using namespace std;

// 1
template<typename T, typename U>
struct is_same2
{
	constexpr static bool value = false;
	//enumot rakni bele vagy mashogy trukkozni, ha nincs cpp17
};

//specializacioja az elozonek
template<typename T>
struct is_same2<T, T>
{
	constexpr static bool value = true;
};
//////// template<>struct is_same2<char, char> { constexpr static bool value = true; };
//////// template<typename T> struct is_integer : public is_same2<T, int> {};
template<typename T> using is_integer = is_same2<T, int>; // kvazi typedef es sablont is tudunk neki adni

// 2
template<typename T>
void printIt(const T& t) 
{
	static_assert(is_integral<T>::value, "T is not an integral type.");
	cout << "integral: " << t << endl;
}

template<>void printIt<std::string>(const std::string &s) { cout << "string: " << s << endl; }

//// namespace A::B {} // van ra lehetoseg

//// variadic sablon
//// template<typename ... Args> // Args lehet 0 db parameter is

// kell az egy parameteres verzio a rekurzio leallitasahoz
template <typename T>T adder(T t) {
	return t;
}

template <typename T, typename... Args>T adder(T first, Args... args) {
	return first + adder(args...);
}

// 4b
template<typename Head, typename... Tail>
void printList2(const Head& head, const Tail&... tail)
{
	cout << head;
	if constexpr (sizeof... (tail) > 0)
	{
		cout << ", ";
		printList2(tail...);
	}
	else
	{
		cout << endl;
	}
	
}

// 4a
template<typename Head>
void printList(const Head& head)
{
	cout << head << endl;
}

// 4a
template<typename Head, typename... Tail>
void printList(const Head& head, const Tail&... tail)
{
	cout << head << ", ";
	printList(tail...);
}

// 5
template<typename... Args>
bool containsZero(const Args&... args)
{
	return ((args == 0) || ...);
}

// 6a
template<typename T>T sqr(T t) { return t * t; }

// rekurzio leallito resze
template<typename T>T squareSum(T t)
{
	return sqr(t);
}

template<typename T, typename... Args>T squareSum(T t, Args... args)
{
	return sqr(t) + squareSum(args...);
}

// 6b
template<typename... Args>auto squareSum2(Args... args) { return (sqr(args) + ...); }
//template<typename... Args>double squareSum2(Args... args) { return (sqr(args) + ...); }
//template<typename... Args>auto squareSum2(Args... args) { return (sqr(args) + ...); } decltype() ....

// hazi: string int kozt is megcsinalni

// 7
// terminalo feltetel
void safe_printf(const char* s)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%') { ++s; }
			else {
				throw runtime_error("Missing argument!");
			}
		}
		cout << *s++;
	}
}

template <typename T, typename... Args>
void safe_printf(const char* s, const T& value, Args... args)
{
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%') { ++s; }
			else {
				cout << value;
				safe_printf(s + 1, args...);
				return;
			}
		}
		cout << *s++;
	}
	throw runtime_error("Extra parameter!");
}


int main()
{
	cout << is_integer<int>::value << endl;
	printIt(12l);
	printIt(string("alma"));
	// printIt(12.5);

	cout << "------------------------------" << endl;
	cout << adder(1, 2, 3, 4, 5, 6, 7, 8, 9) << endl;
	cout << "------------------------------" << endl;
	printList("almafa", "korte", "barackfa");
	cout << "------------------------------" << endl;
	printList2("almafa", "korte", "barackfa");
	cout << "------------------------------" << endl;
	cout << containsZero(1,2,3,4,5,1,3,2,1,1,0,1,1,111,11,1,1,11,1) << endl;
	cout << "------------------------------" << endl;
	cout << squareSum(1, 2, 1, 1, 1, 1, 1) << endl;
	cout << "------------------------------" << endl;
	cout << squareSum2(1, 2, 1, 1, 1, 1, 1) << endl;
	cout << "------------------------------" << endl;
	safe_printf("almafa % % %\n", 12, "korte", 2.8);
	/*try{
	safe_printf("almafa % % % %", 12, "korte", 2.8); // elszall egyikkel
	safe_printf("almafa % % %%", 12, "korte", 2.8); // elszall masikkal
	}
	catch (exception ex)
	{
		cout << ex.what();
	}*/
	cout << "------------------------------" << endl;

	// cout << "------------------------------" << endl;
	// cout << "------------------------------" << endl;

	system("pause");

	return 0;
}
