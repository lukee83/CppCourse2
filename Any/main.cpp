#include <iostream>
#include <string>
#include <vector>
#include "any.h"

using namespace std;

 
int main() 
{ 
	{
		Any a(12), b(10.3);
		a = std::string("almafa");

		string *ptr = a.get<std::string>();

		cout << *ptr << endl;

		//cout << *a.get<int>() << endl; // elszall, string van benne epp

	}

	system("pause");

	return 0;
}
