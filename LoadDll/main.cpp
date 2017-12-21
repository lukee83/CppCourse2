#include <iostream>
#include <string>
#include <vector>

// ez lenne a header tartalma
extern "C" {
	__declspec(dllimport) double dll_adder(double a, double b);
}

using namespace std;

int main()
{

	cout << dll_adder(7, 8) << endl;

	system("pause");

	return 0;
}