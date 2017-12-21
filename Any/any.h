#ifndef ANY_H_
#define ANY_H_
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <typeindex>

namespace 
{
	template<typename T> 
	void deleteAny(void *v)
	{
		delete static_cast<T*>(v);
		std::cout << std::boolalpha << std::is_integral<T>::value << endl;
		//std::cout << typeid(*static_cast<T*>(v)).name() << endl;
		
	}
}

class Any {
private:

	void *data;
	void (*deleter)(void*);
	std::type_index ti;

public:

	

	template<typename T>
	Any(const T &d): ti(std::type_index(typeid(T)))
	{
		data = new T;
		*(static_cast<T*>(data)) = d;
		deleter = deleteAny<T>;
	}

	~Any() 
	{
		deleter(data);
	}

	template<typename T>
	Any& operator= (const T& d)
	{
		deleter(data);

		data = new T;
		*(static_cast<T*>(data)) = d;
		deleter = deleteAny<T>;
		ti = std::type_index(typeid(T));
		return *this;
	}

	template<typename T>
	T* get() 
	{
		if (std::type_index(typeid(T)) == ti)
			return static_cast<T*>(data);
		return nullptr;
	}
};

#endif
