#include <iostream>
#include <string>
#include <vector>

#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mux;
condition_variable cv;

string data1;
bool   ready     = false;
bool   processed = false;

void worker()
{
	string cpy;

	{
		unique_lock<mutex> lck(mux);
		cv.wait(lck, []() { return ready;  });

		cpy = data1; // taroljuk, majd dolgozunk rajta.. stb
		processed = true;

		data1 = "barack";
		lck.unlock(); // nem kell, mert {} kozt van
		cv.notify_one();
	}
	cout << "Tarolt adat: " << cpy << endl;
	
}

int main()
{
	thread th(worker);

	{
		lock_guard<mutex> lck(mux);

		ready = true;
		data1  = "alma";
	}
	
	cv.notify_one();

	{
		unique_lock<mutex> lck(mux);
		cv.wait(lck, []() -> bool { return processed; });

		cout << data1 << endl;

	}
	
	th.join();

	system("pause");

	return 0;
}
