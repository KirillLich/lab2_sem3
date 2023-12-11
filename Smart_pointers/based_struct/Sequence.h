#ifndef SEQUENCE
#define SEQUENCE

template<class T>
class Sequence
{
public:
	virtual ~Sequence() {};
	virtual T& GetFirst() = 0;
	virtual T& GetLast() = 0;
	virtual T& Get(int Index) = 0;
	virtual const size_t GetLenght() = 0;

	virtual void Append(T Item) = 0;
	virtual void Prepend(T Item) = 0;
	virtual void InsertAt(T Item, int Index) = 0;
};

#endif