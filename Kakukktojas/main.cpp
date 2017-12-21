#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ford hiba lesz std::move nelkul
void doIt2(int &i)
{
	cout << "lvalue: " << i << endl;
}

void doIt2(int &&i)
{
	cout << "rvalue: " << i << endl;
}


// forwarding reference regebben "forwarding reference" volt
template <typename T>
void doIt(T &&d)
{
	++d;
	
	// doIt2( d );
	doIt2( std::forward<T>(d) );

	cout << "doIt: " << d << endl;
}

void doIt3(int &&i)
{
	cout << i << endl;
}


int main()
{
	doIt(7);

	int i = 5;
	//doIt(i);
	doIt(std::move(i));
	cout << "i: " << i << endl;
	
	// doIt3(i);    // ford hiba
	// doIt3(move(i)); // ok

	system("pause");

	return 0;
}
