#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <chrono>
/*#include <functional>
#include <memory> // smart ptrs
#include <numeric>
*/
using namespace std;

int main()
{
	vector<int> table(1000);
	generate(table.begin(), table.end(), []() { return 1 /*rand() % 10*/; });
	int sum = 0;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    //#pragma omp parallel for  reduction(+:sum) /**/   num_threads(4)/**/
	for (int i = 0; i < table.size(); ++i)
	{
		sum += table[i];
		//cout << "Adat: " << table[i] << endl;
	}

	cout << "sum: " << sum << endl;
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>> (t2 - t1);

	cout << "duration: " << time_span.count() << endl;
	
	/*
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for reduction(+:sum)
		for (int i = 0; i < table.size(); ++i)
		{
			sum += table[i];
			//cout << "Adat: " << table[i] << endl;
		}
	}
	*/

	//--------------------------------------------------------------------------------------------------	
	
	int a = 0, b = 0;
	#pragma	omp parallel for /*default(none) private(a) shared(b)*/ num_threads(12) // valtozo beallitas
	for (a = 0; a < 50000; ++a)
	{
		//#pragma omp atomic
		b += a;
	}

	/* igy mar hibazik
	int a = 0 , b = 0;
	#pragma	omp parallel for / *default(none) private(a) shared(b)* / num_threads(12) // valtozo beallitas
	for (a = 0; a < 50000; ++a )
	{
	//#pragma omp atomic
	b += a;
	}
	*/

	cout << "b: " << b << endl;

	//--------------------------------------------------------------------------------------------------


	





	system("pause");

	return 0;
}