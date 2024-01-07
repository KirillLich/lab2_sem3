#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H
#include "..\based_struct\Sequence.h"
#include "..\SmartPointer.h"

template<class T>
class ArraySequence :public Sequence<T>
{
	size_t size;
	SmrtPtr<T[]> items;
	SmrtPtr<bool[]> isCellFilled;
public:
	ArraySequence()
	{
		size = 0;
	}
	ArraySequence(T* Items, int count) :items(count), isCellFilled(count)
	{
		size = count;
		for (size_t i = 0; i < count; i++)
		{
			items[i] = Items[i];
			isCellFilled[i] = true;
		}
	}
	ArraySequence(const ArraySequence<T>& Array) :items(Array.items), isCellFilled(Array.isCellFilled)
	{
		size = Array.size;
	}
	~ArraySequence() {};

	T& GetFirst()
	{
		if (size == 0)
			throw std::runtime_error("EmptyArray");
		if(!isCellFilled[0]) throw std::out_of_range("IndexOutOfRange");
		return items[0];
	};
	T& GetLast()
	{
		if (size == 0)
			throw std::runtime_error("EmptyArray");
		if (!isCellFilled[size-1]) throw std::out_of_range("IndexOutOfRange");
		return items[size-1];
	};
	T& Get(int Index)
	{
		if (size == 0)throw std::out_of_range("IndexOutOfRange");
		if (Index<0||Index>=size) throw std::out_of_range("IndexOutOfRange");
		if(!isCellFilled[Index]) throw std::out_of_range("IndexOutOfRange");
		return items[Index];
	};
	const size_t GetLenght()
	{
		return size;
	};

	void Append(T Item) 
	{
		SmrtPtr<T[]> subItems(items);
		SmrtPtr<bool[]> subIsCellFilled(isCellFilled);
		items.Make(size + 1);
		isCellFilled.Make(size + 1);
		for (size_t i = 0; i < size; i++)
		{
			items[i] = subItems[i];
			isCellFilled[i] = subIsCellFilled[i];
		}
		items[size] = Item;
		isCellFilled[size] = true;
		size++;
	};
	void Prepend(T Item) 
	{
		SmrtPtr<T[]> subItems(items);
		SmrtPtr<bool[]> subIsCellFilled(isCellFilled);
		items.Make(size + 1);
		isCellFilled.Make(size + 1);
		for (size_t i = 1; i < size+1; i++)
		{
			items[i] = subItems[i-1];
			isCellFilled[i] = subIsCellFilled[i-1];
		}
		items[0] = Item;
		isCellFilled[0] = true;
		size++;
	};
	void InsertAt(T Item, int Index) 
	{
		if (Index < 0 || Index > size)
			throw std::out_of_range("IndexOutOfRange");

		SmrtPtr<T[]> subItems(items);
		SmrtPtr<bool[]> subIsCellFilled(isCellFilled);
		items.Make(size + 1);
		isCellFilled.Make(size + 1);
		for (size_t i = 0; i < size + 1; i++)
		{
			if (i < Index)
			{
				items[i] = subItems[i];
				isCellFilled[i] = subIsCellFilled[i];
			}
			else if(i == Index)
			{
				items[i] = Item;
				isCellFilled[i] = true;
			}
			else
			{
				items[i] = subItems[i - 1];
				isCellFilled[i] = subIsCellFilled[i - 1];
			}
		}
		size++;
	};
};

#endif