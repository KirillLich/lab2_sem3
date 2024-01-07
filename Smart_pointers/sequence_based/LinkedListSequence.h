#ifndef LINKED_LIST_SEQUENCE_H
#define LINKED_LIST_SEQUENCE_H
#include "..\SmartPointer.h"
#include "..\based_struct\Sequence.h"

template<class T>
class LinkedListSequence :public Sequence<T>
{
	typedef struct Node
	{
		SmrtPtr<Node> next, previous;
		T item;
	}node;

	SmrtPtr<node> first, last;
	size_t length;

public:
	LinkedListSequence()
	{
		length = 0;
	}
	LinkedListSequence(const LinkedListSequence<T>& List)
	{
		SmrtPtr<node> ptr = List.first;
		
		for (size_t i = 0; i < List.length; i++)
		{
			this->Append(ptr.Get().item);
			ptr = ptr.Get().next;
		}
	}
	virtual ~LinkedListSequence() 
	{
		SmrtPtr<node> subNode = first;
		for (size_t i = 0; i < length; i++)
		{
			subNode.~SmrtPtr();
			subNode = subNode.Get().next;
		}
		last.~SmrtPtr();
	}

	T& Get(int Index)
	{
		if (length == 0)
			throw std::runtime_error("EmptyList");
		if (Index < 0 || Index >= length)
			throw std::out_of_range("IndexOutOfRange");

		SmrtPtr<node> out = first;
		for (size_t i = 0; i < Index; i++)
		{
			out = out.Get().next;
		}
		return out.Get().item;
	}
	T& GetFirst()
	{
		if (length == 0)
			throw std::runtime_error("EmptyList");
		return first.Get().item;
	}
	T& GetLast()
	{
		if (length == 0)
			throw std::runtime_error("EmptyList");
		return last.Get().item;
	}
	const size_t GetLenght()
	{
		return length;
	}

	void Append(T Item)
	{
		node subNode;
		subNode.previous = last;
		subNode.item = Item;
		if (length != 0)
		{
			last.Get().next.Make(subNode);
			last = last.Get().next;
			if (length == 1)
			{
				first.Get().next = last;
			}
		}
		else
		{
			first.Make(subNode);
			last = first;
		}
		length++;
	}
	void Prepend(T Item)
	{
		node subNode;
		subNode.next = first;
		subNode.item = Item;
		if (length != 0)
		{
			first.Get().previous.Make(subNode);
			first = first.Get().previous;
			if (length == 1)
			{
				last.Get().previous = first;
			}
		}
		else
		{
			first.Make(subNode);
			last = first;
		}
		length++;
	}
	void InsertAt(T Item, int Index)
	{
		if (Index < 0 || Index > length)
			throw std::out_of_range("IndexOutOfRange");

		if (Index == length)
		{
			this->Append(Item);
			return;
		}

		if (Index == 0)
		{
			this->Prepend(Item);
			return;
		}

		node subNode;
		SmrtPtr<node> indexPosition = first;
		for (size_t i = 0; i < Index; i++)
		{
			indexPosition = indexPosition.Get().next;
		}

		subNode.next = indexPosition;
		subNode.previous = indexPosition.Get().previous;
		subNode.item = Item;

		SmrtPtr<node> subNodePtr;
		subNodePtr.Make(subNode);
		indexPosition.Get().previous.Get().next = subNodePtr;
		indexPosition.Get().previous = subNodePtr;

		length++;
	}
};

#endif 