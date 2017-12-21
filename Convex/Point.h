//#pragma once
#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include <cstring>
using namespace std;
class Point
{
public:
	Point(double x, double y) : x(x), y(y), blob(new char[42])
	{
		memset(blob, 0, 42);
		sprintf_s(blob, 42, "hello");
		cout << blob << endl;
		cout << "ctor" << endl;
	};

	// Note: ha irsz egy copy ctor-t, eltunik a default move constructor
	// vica-versa
	Point(const Point& rhs) : x(rhs.x), y(rhs.y), blob(new char[42])
	{
		//cout << "copy begin" << endl;
		memcpy(blob, rhs.blob, 42);
		cout << "copy end" << endl;
	}

	Point& operator=(const Point& rhs)
	{
		if (this != &rhs)
		{
			x = rhs.x;
			y = rhs.y;

			// check blob!! free up
			if (blob)
				delete[] blob;

			blob = new char[42];
			memcpy(blob, rhs.blob, 42);
		}
		cout << "operator=" << endl;
		return *this;
	}

	Point(Point&& p) : x(p.x), y(p.y) //, blob(nullptr)
	{
		//el kell tole venni az eroforrasokat
		//ertelmes allapotot kell hagynunk
		//cout << "move copy ctor begin()" << endl;
		// std::swap(blob, p.blob);

		blob = p.blob;
		p.x = 0;
		p.y = 0;

		p.blob = nullptr;

		cout << "move copy ctor end()" << endl;
	}

	Point& operator=(Point&& rhs)
	{
		//cout << "operator move= begin()" << endl;
		if (this != &rhs)
		{
			x = rhs.x;
			y = rhs.y;

			if (blob)
				delete[] blob;

			blob = rhs.blob;
			memcpy(blob, rhs.blob, 42);

			rhs.blob = nullptr;
			rhs.y = 0.;
			rhs.x = 0.;
		}

		cout << "operator move= end()" << endl;
		return *this;
	}

	virtual ~Point()
	{
		delete[] blob;
		cout << "dtor" << endl;
	};

/*private:*/
	double x, y;
private:
	char *blob;
};

bool operator<(const Point &p1, const Point &p2)
{
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

#endif

