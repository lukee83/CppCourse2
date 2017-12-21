#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <thread>

// 1
#include <future>

using namespace std;

void call_from_thread()
{
	cout << "~ in thread ~" << endl;
}

int add_async(int a, int b)
{
	cout << "~ in adding ~" << endl;
	return a + b;
}

// thread biztos
std::once_flag flag;

void do_something()
{
	std::call_once(flag, []() {cout << "~ Called once ~" << endl; });
	// ha 2x, akkor mutex vagy atomic valtozo
	cout << "~ Called each time ~" << endl;
}



int main()
{
	/*{ // future
		cout << "begin" << endl;

		future<void> fut = async(/*launch::async,* / call_from_thread);
		
		cout << "trallallalalaa" << endl;
		cout << "trallallalalaa" << endl;

		fut.get(); // blokkol, mig nem lesz kesz. (launch::deferred eseten szimpla fv hivas lesz ez)

		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	/*{ // future
		cout << "begin" << endl;

		// variadic sablon
		// kivetelkezeles...
		future<int> fut = async(launch::async, add_async, 5, 7);

		cout << "trallallalalaa" << endl;
		cout << "trallallalalaa" << endl;

		cout << "Eredmeny: " << fut.get() << endl;

		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	/*{
		cout << "begin" << endl;

		// atomic<double> c = 2.9; ???
		double c = 3;
		// referencianal mutexel vedeni
		future<double> fut = async(launch::async, [&c](double a, double b) { cout << "~ in lambda adding ~"<< endl; return c + a / b; }, 10.0, 1.0 /*0* / );

		cout << "trallallalalaa" << endl;
		cout << "trallallalalaa" << endl;

		cout << "Eredmeny: " << fut.get() << endl;


		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	/*{
		cout << "begin" << endl;

		promise<int> prom;
		future<int> fut = prom.get_future();

		//cout << "Eredmeny: " << fut.get() << endl;

		prom.set_value(12);
		
		cout << "Eredmeny (promise utan): " << fut.get() << endl;

		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	/*{
		cout << "begin" << endl;

		thread th1(call_from_thread);
		thread th2(add_async, 5, 7); // csak ertek szerint adja at, referencianal trukkozni kell

		cout << "trallallalalaa" << endl;
		cout << "trallallalalaa" << endl;

		th1.join(); // kulonben elszall, ha ez nincs itt VAGY detach
		th2.join();

		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	/*{
		cout << "begin" << endl;

		packaged_task<int(int, int)> task(add_async);

		future<int> fut = task.get_future();

		thread th1(call_from_thread);
		thread th2(std::move(task), 12, 5); // move azert, mert copyzni nem lehet, mert ket ugyanaz a future, ket ua. promise lenne

		cout << "trallallalalaa" << endl;
		cout << "trallallalalaa" << endl;

		cout << "Eredmeny: " << fut.get() << endl;

		th1.join();
		th2.join();

		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	/*{
		cout << "begin" << endl;

		vector<future<int>> v;

		for (int i = 0; i<10; ++i)
		{
			v.push_back(
				future<int>(
					std::async([](int i, int j) 
						{
							cout << i << endl;
							return i * j;
						}, i, 2)
					));
		}

		for (auto &fut : v)
		{
			cout << "Eredmeny: " << fut.get() << endl;
		}

		cout << "end" << endl;
	}*/

	cout << "--------------------" << endl;

	{
		cout << "begin" << endl;

		thread th1(do_something);
		thread th2(do_something);
		thread th3(do_something);
		thread th4(do_something);

		th1.join();
		th2.join();
		th3.join();
		th4.join();

		cout << "end" << endl;
	}

	cout << "--------------------" << endl;

	{
		cout << "begin" << endl;
		cout << "end" << endl;
	}

	system("pause");

	return 0;
}