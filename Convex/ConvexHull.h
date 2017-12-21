//#pragma once
#ifndef _CONVEX_HULL_H
#define _CONVEX_HULL_H

#include <set>
#include "Point.h"

using namespace std;

class ConvexHull 
{
private: 
	set<Point> hull;

	void convex_hull(const set<Point> &ps, set<Point> &h) 
	{
		// ps --> h
	
	}

public: 
	ConvexHull() = default;
	ConvexHull(const set<Point> &ps)
	{
		convex_hull(ps, hull);
	}

	ConvexHull(std::initializer_list<Point> il)
	{
		set<Point> ps(il);
		convex_hull(ps, hull);
	}

	ConvexHull(set<Point> &&ps)
	{
		convex_hull(ps, hull);
		// empty rhs ps
	}

	void add(set<Point> && ps)
	{
		ps.insert(hull.begin(), hull.end());
		hull.clear();
		convex_hull(ps, hull);
		//ps.clear();
	}

};

#endif // !_CONVEX_HULL_H

