#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "Point.h"


using namespace std;

void test1(Point&& p)
{
	cout << "vvvvvvvvvvvvvv" << endl;
	vector<Point> po;
	//po.push_back(p); // defaultbol lvalue -> rvalue ; copy-t fog kiirni, mert csak cpy constructor hivodik meg
	po.push_back(std::move(p)); // igy mar kikenyszeritve lvalue-kent is hasznalja
	cout << "^^^^^^^^^^^^^" << endl;
}


int main()
{
	{
	vector<Point> points;
	//points.reserve(5); // ha ez nem lesz a vector meretet folyamatosan ketszerezi

	Point p1(5.2, 3.3), p2{ 5.5, 4.4 }, p3 = p2;

	cout << "------------" << endl;

	points.push_back(std::move(p1));
	points.push_back(p2);
	//points.push_back(std::move(p3));
	
	cout << "------------" << endl;
	
	}

	{
		Point p1(5.2, 3.3);
		test1(std::move(p1)); // meaning: static_cast<Point&&>(p1)
	}

	
	system("pause");

	return 0;
}