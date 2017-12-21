#ifndef ANY_H_
#define ANY_H_
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <typeindex>

constexpr unsigned fact(unsigned f)
{
	if (1 == f) return 1;
	return f * fact(f - 1);
}

class Any final
{
private:
	
	struct placeholder
	{
		virtual ~placeholder() {}
	};

	template<typename T>
	struct holder final : public placeholder 
	{
		T *data;
		holder(const T& d) 
		{
			data = new T;
			*data = d;
		}
		
		~holder() 
		{ 
			delete data; 
		}
	};

	placeholder *value; // statikus - dinamikus tipus, oszosztaly ptr-en keresztul tudni fogja magarol, hogy mi
	
public:
	template <typename T>
	Any(const T& d) : value(new holder<T>(d)) {}

	~Any() { delete value; }

	template<typename T>
	Any& operator=(const T& d) 
	{
		delete value;
		value = new holder<T>(d);
		return *this;
	}
	
	template <typename T>
	T* get()
	{
		holder<T> *h = dynamic_cast<holder<T>*>(value);
		if (h)
		{
			return h->data;
		}
		return nullptr;
	}

};

#endif
