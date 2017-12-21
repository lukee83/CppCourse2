#include <iostream>
#include <string>
#include "eq.h"

using namespace std;

int main()
{
	// egyenletrendszer
	Eq eq;
	Eq::Var x = eq.getVar();
	Eq::Var y = eq.getVar();
	Eq::Var z = eq.getVar();

	Eq::Expr e = x;
	e += y;
	e += 3 * z;
	
	//e.print();

	/*Eq::Row r = eq.addEq(e, 4); csak lustak vagyunk */ eq.addEq(e, 4);

	//Eq::Row r = eq.getRow();
	//r.set(e, 12);
	
	eq.print();

	//r.solve(); -> matrix -> megold -> vissza

	system("pause");

	return 0;
}