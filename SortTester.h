#ifndef SORT_TESTER_H
#define SORT_TESTER_H
#include <assert.h>
#include "Sorting.h"
#include "Smart_pointers/sequence_based/ArraySequence.h"
#include "Comparators.h"

class SortTester
{
	using Sort = Sequence<int>* (*)(Sequence<int>*, Comp<int>);

	void EmptySequence(Sort func)
	{
		ArraySequence<int>* arr = new ArraySequence<int>;
		try
		{
			func(arr, CompIncreasingOrder);
		}
		catch (const std::exception& e)
		{
			delete arr;
			assert(false);
		}
		delete arr;
	}
	void IntSequenceInDecreasingOrder(Sort func)
	{
		ArraySequence<int>* arr = new ArraySequence<int>;

		const size_t arraySize = 5;
		//array {10, 3, 7, -1, 6}
		arr->Append(10);
		arr->Append(3);
		arr->Append(7);
		arr->Append(-1);
		arr->Append(6);
		int sortArr[arraySize] = { -1,3,6,7,10 };

		try {

		func(arr, CompIncreasingOrder);
		}
		catch (std::exception&) {
			delete arr;
			assert(false);
		}
		
		for (size_t i = 0; i < arraySize; i++)
		{
			assert(arr->Get(i) == sortArr[i]);
		}
		delete arr;
	}
	void IntSequenceInIncreasingOrder(Sort func)
	{
		ArraySequence<int>* arr = new ArraySequence<int>;

		const size_t arraySize = 5;
		//array {10, 3, 7, -1, 6}
		arr->Append(10);
		arr->Append(3);
		arr->Append(7);
		arr->Append(-1);
		arr->Append(6);
		int sortArr[5] = { 10, 7, 6, 3, -1 };

		try
		{
			func(arr, CompDecreasingOrder);
		}
		catch (const std::exception&)
		{
			delete arr;
			assert(false);
		}
		for (size_t i = 0; i < arraySize; i++)
		{
			assert(arr->Get(i) == sortArr[i]);
		}
		delete arr;
	}

	void Bubble()
	{
		EmptySequence(BubbleSort);
		IntSequenceInDecreasingOrder(BubbleSort);
		IntSequenceInIncreasingOrder(BubbleSort);
	}

	void Insertion()
	{
		EmptySequence(InsertionSort);
		IntSequenceInDecreasingOrder(InsertionSort); 
		IntSequenceInIncreasingOrder(InsertionSort);
	}

	void Quick()
	{
		EmptySequence(QuickSort);
		IntSequenceInDecreasingOrder(QuickSort);
		IntSequenceInIncreasingOrder(QuickSort);
	}
public:
	SortTester() = default;
	void RunTests()
	{
		Bubble();
		Insertion();
		Quick();
	}
};

#endif // !SORT_TESTER_H