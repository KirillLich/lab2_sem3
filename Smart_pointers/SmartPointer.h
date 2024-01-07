#ifndef SMART_POINTER
#define SMART_POINTER
#include <algorithm>
#include <stdexcept>

template<typename T>
class SmrtPtr
{
public:

	//5 constructors
	SmrtPtr();
	SmrtPtr(T* tPtr);
	SmrtPtr(const T& item);
	SmrtPtr(const SmrtPtr<T>& sPtr);

	template<typename P>
	SmrtPtr(const SmrtPtr<P>& sPtr);
	
	//1 destructor
	~SmrtPtr();

	//make and get functions
	void Make(const T& item);
	T& Get();

	//3 operators (1 overloaded)
	T& operator*();
	void operator=(SmrtPtr<T>& sPtr);
	template<typename P>
	void operator=(SmrtPtr<P>& sPtr);
	T* operator->();

private:

	void ClearPtr();

	T* ptr;
	size_t* counter;
	friend class SmrtPtr;
};

//constructors realizations
template<typename T>
SmrtPtr<T>::SmrtPtr()
{
	this->ptr = NULL;
	this->counter = NULL;
}

template<typename T>
SmrtPtr<T>::SmrtPtr(T* tPtr)
{
	this->ptr = tPtr;
	if (ptr != NULL) counter = new size_t(1);
	else counter = NULL;
}

template<typename T>
SmrtPtr<T>::SmrtPtr(const T& item)
{
	counter = new size_t(1);
	this->ptr = new T(item);
}

template<typename T>
SmrtPtr<T>::SmrtPtr(const SmrtPtr<T>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}

	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

template<typename T> template<typename P>
SmrtPtr<T>::SmrtPtr(const SmrtPtr<P>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}

	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL) {
		throw std::runtime_error("Class P is not subclass of class T");
	}
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
};

/*

if( adad )
	a;
	b;
asdasdsa;

*/

//destructor realization
template<typename  T>
SmrtPtr<T>::~SmrtPtr()
{
	this->ClearPtr();
}

//get/make realizations
template<typename T>
T& SmrtPtr<T>::Get()
{
	if (this->ptr == NULL)
	{
		throw(std::runtime_error("Empty pointer"));
	}
	return *(this->ptr);
}

template <typename T>
void SmrtPtr<T>:: Make(const T& item)
{
	this->ClearPtr();

	counter = new size_t(1);
	this->ptr = new T(item);
};

//operators realizations
template<typename T>
T& SmrtPtr<T>::operator*()
{
	return this->Get();
}

template<typename T>
void SmrtPtr<T>::operator=(SmrtPtr<T>& sPtr)
{
	this->ClearPtr();

	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	if (this->counter != NULL) (*this->counter)++;
}

template<typename T> template<typename P>
void SmrtPtr<T>::operator=(SmrtPtr<P>& sPtr)
{
	this->ClearPtr();

	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::runtime_error("Class P is not subclass of class T");
	else
		this->counter = sPtr.counter;
	if (this->counter != NULL) (this->counter)++;
}

template <typename T>
void SmrtPtr<T>::ClearPtr()
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			delete counter;
		}
	}
}

template <typename T>
T* SmrtPtr<T>::operator->()
{
	return this->ptr;
}

//next class is for arrays

template<typename T>
class SmrtPtr<T[]>
{
public:

	//4 constructors
	SmrtPtr();
	SmrtPtr(const size_t size);
	SmrtPtr(const SmrtPtr<T[]>& sPtr);

	template<typename P>
	SmrtPtr(const SmrtPtr<P[]>& sPtr);

	//1 destructor
	~SmrtPtr();

	//make and get functions
	void Make(const size_t size);
	T& Get(size_t index);

	//sort function
	void sort(size_t length, bool(*comp)(T a, T b));

	//3 operators (1 overloaded)
	T& operator[](size_t index);
	void operator=(SmrtPtr<T[]>& sPtr);

	template<typename P>
	void operator=(SmrtPtr<P[]>& sPtr);

	T* operator->();

private:

	void clearPtr();

	T* ptr;
	size_t* counter;
	friend class SmrtPtr;
};

//constructors realizations
template<typename T>
SmrtPtr<T[]>::SmrtPtr()
{
	this->counter = NULL;
	this->ptr = NULL;
}

template<typename T>
SmrtPtr<T[]>::SmrtPtr(const size_t size)
{
	this->counter = new size_t(1);
	this->ptr = new T[size];
}

template<typename T>
SmrtPtr<T[]>::SmrtPtr(const SmrtPtr<T[]>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

template<typename T> template<typename P>
SmrtPtr<T[]>::SmrtPtr(const SmrtPtr<P[]>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::runtime_error("Class P is not subclass of class T");
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

//destructor realization
template<typename  T>
SmrtPtr<T[]>::~SmrtPtr()
{
	this->clearPtr();
}

//get/make realization
template<typename T>
T& SmrtPtr<T[]>::Get(size_t index)
{
	if (this->ptr == NULL)
	{
		throw(std::runtime_error("Empty pointer"));
	}
	return (this->ptr)[index];
}

template<typename T>
void SmrtPtr<T[]>::Make(const size_t size)
{
	this->clearPtr();
	
	counter = new size_t(1);
	this->ptr = new T[size];
}

//operators realization
template<typename T>
T& SmrtPtr<T[]>::operator[](size_t index)
{
	return (this->ptr)[index];
}

template<typename T>
void SmrtPtr<T[]>::operator=(SmrtPtr<T[]>& sPtr)
{
	this->clearPtr();

	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	if (this->counter != NULL) (this->counter)++;
}

template<typename T> template<typename P>
void SmrtPtr<T[]>::operator=(SmrtPtr<P[]>& sPtr)
{
	this->clearPtr();

	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::runtime_error("Class P is not subclass of class T");
	else
		this->counter = sPtr.counter;
	if (this->counter != NULL) (this->counter)++;
}

template <typename T>
T* SmrtPtr<T[]>::operator->()
{
	return this->ptr;
}

template <typename T>
void SmrtPtr<T[]>::clearPtr()
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete [] ptr;
			delete counter;
		}
	}
}
#endif // !SMART_POINTER