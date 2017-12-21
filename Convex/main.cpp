#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <array>
#include <vector>
// #include <initializer_list>
#include "ConvexHull.h"
#include "Point.h"


using namespace std;

int main()
{
	{
		ConvexHull h{ {3.6, 7.1},  {.8, 7.8},  {3.3, 5.5} };

		set<Point> sp;
		Point p1(3.5, 3.3), p2{ 5.5, 4.4 }, p3 = p2;
		sp.insert(p1); sp.insert(p2); sp.insert(p3);

		h.add(std::move(sp));

	}
	system("pause");

	return 0;
}