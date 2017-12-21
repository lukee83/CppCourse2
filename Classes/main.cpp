#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Foo
{

private:
	string name;

public:
	Foo(const string& name) :name(name) {}
	Foo() = default;

	Foo(const Foo&) = delete; // Foo(const Foo&) = delete;  : explicit delete copy constructor

	std::string getName() const /*noexcept*/ { return name; }

	virtual int magic() const 
	{
		return 7;
	}

};

class Bar final : public Foo // can be final class as well
{
public:
	int magic() const override final { return 8; } // virtual function override
};

class Baz : public Bar
{
public:
//hack	using Bar::magic;
	//int magic() const {}; Error
};



int main()
{
	Foo f("almafa");
	Foo g; //Foo g;    Error: no default constructor Solution: add default constructor; Foo() = default;
	
	system("pause");

	return 0;
}