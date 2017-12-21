#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <array>
#include <vector>
#include <functional>
#include <memory> // smart ptrs


using namespace std;

struct Point
{
	Point(double x, double y) : x(x), y(y) {}
	double x, y;


};

int main()
{
	{
		std::shared_ptr<int> p1(nullptr);
		std::shared_ptr<int> p2(new int);
		std::shared_ptr<int> p3(new int, [](int*p) {cout << "Byebye" << endl; delete p; }); // setup deleter function
		std::shared_ptr<int> p4(p2);
		std::shared_ptr<int> p5(std::move(p4));

		*p2 = 5;
		cout << *p5 << endl;

		cout << "p2.use_count: " << p2.use_count() << endl;
		cout << "p4.use_count: " << p4.use_count() << endl;
		cout << "p5.use_count: " << p5.use_count() << endl;
	}
	cout << "---------------------------------------" << endl;
	
	weak_ptr<int> wp;

	{
		std::shared_ptr<int> sp(new int);
		*sp = 3;
		std::shared_ptr<int> sp2(sp);

		cout << "sp.use_count: " << sp.use_count() << endl;

		wp = sp; // nem birtoklo pointer; shared ptr-bol tudom csinalni;
		//wp.expired() // is hasznalhato
		auto asp = wp.lock();

		if (asp) // megfogom, lockolom a mutatott shared ptr-t. ha nem ad true-t ad vissza, nincs mar mogotte semmi
		{
			*asp = 5;
		}
		else 
		{
			cout << "nincs mar mogotte semmi _1!" << endl;
		}

		cout << *sp << endl;
	}
	

	if (auto asp = wp.lock()) *asp = 6;
	else cout << "nincs mar mogotte semmi _2!" << endl;
	

	cout << "---------------------------------------" << endl;

	{
		shared_ptr<Point> sp1(new Point(1.2, 3.4));
		shared_ptr<Point> sp2 = make_shared<Point>(1.2, 3.4);

	}

	cout << "---------------------------------------" << endl;

	{
		unique_ptr<int> up(new int); // nem masolhato, csak 1 db van benne
		unique_ptr<Point> up2 = make_unique<Point>(.3, 4.);

		cout << up2->x << ", " << up2->y << endl;

		unique_ptr<Point> up3(std::move(up2));

		// .get() // get the naked ptr
		Point *pp = up3.get(); //
		
		up3.release();
		delete pp;

	}

	system("pause");

	return 0;
}