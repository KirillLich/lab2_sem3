#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H
#include "..\based_struct\Sequence.h"
#include "..\SmartPointer.h"

template<class T>
class ArraySequence :public Sequence<T>
{
	size_t size;
	SmrtPtr<T[]> items;
	SmrtPtr<bool[]> flags;
public:
	ArraySequence()
	{
		size = 0;
	}
	ArraySequence(T* Items, int count) :items(count), flags(count)
	{
		size = count;
		for (size_t i = 0; i < count; i++)
		{
			items[i] = Items[i];
			flags[i] = true;
		}
	}
	ArraySequence(const ArraySequence<T>& Array) :items(Array.items), flags(Array.flags)
	{
		size = Array.size;
	}
	~ArraySequence() {};

	T& GetFirst()
	{
		if (size == 0)
			throw std::exception("EmptyArray");
		if(!flags[0]) throw std::out_of_range("IndexOutOfRange");
		return items[0];
	};
	T& GetLast()
	{
		if (size == 0)
			throw std::exception("EmptyArray");
		if (!flags[size-1]) throw std::out_of_range("IndexOutOfRange");
		return items[size-1];
	};
	T& Get(int Index)
	{
		if (size == 0)throw std::out_of_range("IndexOutOfRange");
		if (Index<0||Index>=size) throw std::out_of_range("IndexOutOfRange");
		if(!flags[Index]) throw std::out_of_range("IndexOutOfRange");
		return items[Index];
	};
	const size_t GetLenght()
	{
		return size;
	};

	void Append(T Item) 
	{
		SmrtPtr<T[]> subItems(items);
		SmrtPtr<bool[]> subFlags(flags);
		items.make(size + 1);
		flags.make(size + 1);
		for (size_t i = 0; i < size; i++)
		{
			items[i] = subItems[i];
			flags[i] = subFlags[i];
		}
		items[size] = Item;
		flags[size] = true;
		size++;
	};
	void Prepend(T Item) 
	{
		SmrtPtr<T[]> subItems(items);
		SmrtPtr<bool[]> subFlags(flags);
		items.make(size + 1);
		flags.make(size + 1);
		for (size_t i = 1; i < size+1; i++)
		{
			items[i] = subItems[i-1];
			flags[i] = subFlags[i-1];
		}
		items[0] = Item;
		flags[0] = true;
		size++;
	};
	void InsertAt(T Item, int Index) 
	{
		if (Index < 0 || Index > size)
			throw std::exception("IndexOutOfRange");

		SmrtPtr<T[]> subItems(items);
		SmrtPtr<bool[]> subFlags(flags);
		items.make(size + 1);
		flags.make(size + 1);
		for (size_t i = 0; i < size + 1; i++)
		{
			if (i < Index)
			{
				items[i] = subItems[i];
				flags[i] = subFlags[i];
			}
			else if(i == Index)
			{
				items[i] = Item;
				flags[i] = true;
			}
			else
			{
				items[i] = subItems[i - 1];
				flags[i] = subFlags[i - 1];
			}
		}
		size++;
	};
};

#endif