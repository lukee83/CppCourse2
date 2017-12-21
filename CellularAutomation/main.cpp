#include <iostream>
#include <string>
#include <vector>
#include "CA.h"

// Wolfram online matek konyv; szamelmeleti izgalmas dolgok
// sejtautomatak, ...
// Wolfram: new kind of science

using namespace std;

int main()
{
	CA c(79, 102);
	cout << c << endl;

	for (int i = 0; i < 10; ++i)
	{
		c.run();
		cout << c << endl;
	}
	
	system("pause");

	return 0;
}