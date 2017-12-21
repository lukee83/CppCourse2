#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>


using namespace std;

void firstFunction()
{
	cout << "firstFunction" << endl;
}

void secondFunction()
{
	cout << "secondFunction" << endl;
}

void thirdFunction()
{
	cout << "thirdFunction" << endl;
}

void work1()
{
#pragma omp critical(kiiratas)
	cout << "work1" << endl;
}

void work2()
{
#pragma omp critical(kiiratas)
	cout << "work2" << endl;
}


void work3()
{
#pragma omp critical(kiiratas)
	cout << "work3" << endl;
}


void work4()
{
#pragma omp critical(kiiratas)
	cout << "work4" << endl;
}


void work5()
{
#pragma omp critical(kiiratas)
	cout << "work5" << endl;
}

void work6()
{
#pragma omp critical(kiiratas)
	cout << "work6" << endl;
}


int main()
{
	string s1 = "x", s2 = "y";
	int c = 3;


	/*#pragma omp parallel num_threads(12)
	{
		s1 += "k";
		c += 7;
		//cout << "Hello World!" << endl;
		cout << "s1: " << s1 << ", s2: " << s2 << ",c " << c << endl;
	}*/

	/*#pragma omp parallel private(s1, c) shared(s2) num_threads(12)
	{
		s1 += "k";
		//c += 7;
		//cout << "Hello World!" << endl;
		//cout << "s1: " << s1 << ", s2: " << s2 << ",c " << c << endl;
		cout << "s1: " << s1 << ", s2: " << s2 << endl;
	}*/

    /*#pragma omp parallel private(c) firstprivate(s1) shared(s2) num_threads(12)
	{
		//firstprivate() behozza, inicializal a kulso ertekkel, majd minden threadnel private lesz
		s1 += "k";
		//s2 += "v"; uncomment to check shared()
		//c += 7;
		//cout << "Hello World!" << endl;
		//cout << "s1: " << s1 << ", s2: " << s2 << ",c " << c << endl;
		cout << "s1: " << s1 << ", s2: " << s2 << endl;
	}*/

	// lastprivate nem mukodik meg ezen a platformon
	/*#pragma omp parallel private(c) firstprivate(s1) shared(s2) num_threads(12)
	{
		s1 += "k";
		cout << "s1: " << s1 << ", s2: " << s2 << endl;
	}*/

	//cout << "after parallel block:" << endl;
	//cout << "s1: " << s1 << ", s2: " << s2 << endl;



	/*#pragma omp parallel num_threads(12)
	{
		firstFunction();
		#pragma omp barrier // bevarjak egymas. pl implicit barrier a for ciklus vegen
		secondFunction();
	}*/

	cout << "---------------------------------------" << endl;
	/*
	#pragma omp parallel num_threads(12)
	{
		//1,3: x12
		//2: x1 fusson le

		firstFunction();
		#pragma omp single nowait // nowait torli az implicit barriert
		{
			secondFunction();
		} // implicit barrer is here
		
		thirdFunction();
	}
	*/
	cout << "---------------------------------------" << endl;

	/*#pragma omp parallel num_threads(12)
	{
	
		firstFunction();
		#pragma omp master // fo szal fogja vegrehajtani
		{
			secondFunction();
		} // ilyenkor nincs implicit barrier

		thirdFunction();
	}*/

	cout << "---------------------------------------" << endl;

	#pragma omp parallel num_threads(12)
	{

		work1();

		#pragma omp sections
		{
			work2();

			#pragma omp section
			{
				work3();
				work4();
			}

			#pragma omp section
			{
				work5();
			}
		}
		
		work6();

	}

/*
#pragma omp atomic
	x += 7;

#pragma omp atomic read
	val = x;

#pragma omp atomic write
	x = expr;

#pragma omp atomic update
	++x; x--; x *= 3;
*/






	system("pause");

	return 0;
}