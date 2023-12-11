#ifndef SORT_TESTER_H
#define SORT_TESTER_H
#include <assert.h>
#include "Sorting.h"
#include "Smart_pointers/sequence_based/ArraySequence.h"

template<typename T>
int CompIncreasingOrder(T first, T second)
{
	return first > second;
}

template<typename T>
int CompDecreasingOrder(T first, T second)
{
	return first < second;
}

class SortTester
{
	void SortTestEmptySequence(Sequence<int>*(*SortingFunction)(Sequence<int>*, int(*)(int,int)))
	{
		ArraySequence<int>* arr = new ArraySequence<int>;
		try
		{
			SortingFunction(arr, CompIncreasingOrder);
		}
		catch (const std::exception& e)
		{
			delete arr;
			assert(e.what());
		}
		delete arr;
	}
	void SortTestIntSequenceInDecreasingOrder(Sequence<int>* (*SortingFunction)(Sequence<int>*, int(*)(int, int)))
	{
		ArraySequence<int>* arr = new ArraySequence<int>;

		//array {10, 3, 7, -1, 6}
		arr->Append(10);
		arr->Append(3);
		arr->Append(7);
		arr->Append(-1);
		arr->Append(6);
		int sortArr[5] = { -1,3,6,7,10 };

		try {

		SortingFunction(arr, CompIncreasingOrder);
		}
		catch (std::exception&) {
			delete arr; arr = nullptr;
			assert(true);
		}
		
		for (size_t i = 0; i < 5; i++)
		{
			assert(arr->Get(i) == sortArr[i]);
		}
		delete arr;
	}
	void SortTestIntSequenceInIncreasingOrder(Sequence<int>* (*SortingFunction)(Sequence<int>*, int(*)(int, int)))
	{
		ArraySequence<int>* arr = new ArraySequence<int>;

		//array {10, 3, 7, -1, 6}
		arr->Append(10);
		arr->Append(3);
		arr->Append(7);
		arr->Append(-1);
		arr->Append(6);
		int sortArr[5] = { 10, 7, 6, 3, -1 };

		try
		{
			SortingFunction(arr, CompDecreasingOrder);
		}
		catch (const std::exception&)
		{
			delete arr;
			assert(false);
		}
		for (size_t i = 0; i < 5; i++)
		{
			assert(arr->Get(i) == sortArr[i]);
		}
		delete arr;
	}

	void BubbleSortTests()
	{
		SortTestEmptySequence(BubbleSort);
		SortTestIntSequenceInDecreasingOrder(BubbleSort);
		SortTestIntSequenceInIncreasingOrder(BubbleSort);
	}

	void InsertionSortTests()
	{
		SortTestEmptySequence(InsertionSort);
		SortTestIntSequenceInDecreasingOrder(InsertionSort); 
		SortTestIntSequenceInIncreasingOrder(InsertionSort);
	}

	void QuickSortTests()
	{
		SortTestEmptySequence(QuickSort);
		SortTestIntSequenceInDecreasingOrder(QuickSort);
		SortTestIntSequenceInIncreasingOrder(QuickSort);
	}
public:
	SortTester()
	{
		BubbleSortTests();
		InsertionSortTests();
		QuickSortTests();
	}
};

#endif // !SORT_TESTER_H