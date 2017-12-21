#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>


using namespace std;

template<typename T>
class Box
{
public:
	explicit Box(const T &num) : num(num) {}   // 5-> Box<int>(5) (1 param eseten letiltom az automatikus tipuskonverziot

	T     num;
	mutex mux;
};


template<typename T>
void transfer(Box<T> &b1, Box<T> &b2, T num) // num darabot kiveszunk az elsobol es belerakjuk a masodikba
{
	//finomhangolhato
	unique_lock<mutex> lc1(b1.mux, std::defer_lock); // meg ne lockolja le, csak letrehozzuk a unique_lock-ot
	unique_lock<mutex> lc2(b2.mux, std::defer_lock);

	std::lock(lc1, lc2);
	//try_lock(); // probal lockolni. ha nem megy, megyunk tovabb, majd lockoljunk kesobb

	b1.num -= num;
	b2.num += num;

	cout << "Hello from thread: " << this_thread::get_id() << endl;
}



int main()
{
	Box<unsigned> b1(12), b2(8), b3(12);
	
	// std::ref() -> tudunk vectorban tarolni referenciakat ezek utan
	// std::cref()

	thread t1(transfer<unsigned>, std::ref(b1), std::ref(b2), 3);
	thread t2(transfer<unsigned>, std::ref(b2), std::ref(b1), 5);
	thread t3(transfer<unsigned>, std::ref(b3), std::ref(b2), 3);

	t1.join(); t2.join(); t3.join();

	cout << "b1: " << b1.num << ", b2: " << b2.num << ", b3: " << b3.num << endl;

	system("pause");

	return 0;
}
