#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mux;
condition_variable cv;
bool ready = false;

void print_it(int i)
{
	{
		unique_lock<mutex> lc(mux);
		// vagy try_lock es ha nem sik, akkor alszik tovabb

		while (!ready) cv.wait(lc);
		
		// ready = false;
	}

	cout << "Hello from " << this_thread::get_id() << ", i: " << i << endl;
	
}

void go()
{
	{
		lock_guard<mutex> lck(mux);
		// + shared_lock, ...
		ready = true;
		cv.notify_all();
	}

	cout << "~ go ~" << endl;
}

int main()
{
	thread th[10];
	
	for (int i = 0; i < 10; ++i)
	{
		th[i] = thread(print_it, i);
	}

	cout << "go>>>>>>" << endl;

	go();

	cout << "<<<<<<go" << endl;

	for (auto& item : th)
	{
		item.join();
	}

	system("pause");

	return 0;
}