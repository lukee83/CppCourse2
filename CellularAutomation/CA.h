#ifndef _CA_H
#define _CA_H

#include <iostream>

using namespace std;

class CA 
{
private:
	int size;
	int rule;
	int age;
	char *p;


public:
	CA(int size, int rule) : size(size), rule(rule), age(0)
	{ 
		p = new char[size +2];
		memset(p, 0, size + 2);
		p[(size / 2) + 1] = 1;

	}
	
	~CA() { delete[] p; }

	CA(const CA&) = delete;
	CA(CA&&) = delete;


	void run(int gen = 1);

	int getAge() const { return age; }

	void __print(ostream& out) const 
	{
		for (int i = 0; i < size; ++i)
		{
			//cout << static_cast<char>('0' + *(p + i));
			if (*(p + i + 1))
			{
				cout << static_cast<char>(1);
			}
			else {
				cout << ' ';
			}
		}
	}
 
};

inline ostream& operator<<(ostream& out, const CA &c)
{
	c.__print(out);
	return out;
}

#endif // !_CA_H

