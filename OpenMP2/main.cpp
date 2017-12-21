#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>


using namespace std;

int main()
{

	#pragma omp parallel
	{
		cout << "Hello World!" << endl;
	}

	system("pause");

	return 0;
}