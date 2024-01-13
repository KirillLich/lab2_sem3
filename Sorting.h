#ifndef SORTING_H
#define SORTING_H
#include "Smart_pointers/based_struct/Sequence.h"

template <typename T>
using Comp = bool(*)(T, T);

template<typename T>
Sequence<T>* BubbleSort(Sequence<T>* seq, Comp<T> func)
{
	if (seq == nullptr)
	{
		return seq;
	}
	size_t length = seq->GetLenght();
	if (length == 0)
	{
		return seq;
	}
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (func(seq->Get(j), seq->Get(j + 1)))
			{
				T item = seq->Get(j);
				seq->Get(j) = seq->Get(j + 1);
				seq->Get(j + 1) = item;
			}
		}
	}
	return seq;
}

template<typename T>
Sequence<T>* InsertionSort(Sequence<T>* seq, Comp<T> func)
{
	if (seq == nullptr)
	{
		return seq;
	}
	size_t length = seq->GetLenght();
	if (length == 0)
	{
		return seq;
	}
	for (size_t i = 0; i < length - 1; i++)
	{
		T item = seq->Get(i + 1);
		size_t j = i + 1;
		while (j > 0 && func(seq->Get(j - 1), item))
		{
			seq->Get(j) = seq->Get(j - 1);
			j--;
		}
		seq->Get(j) = item;
	}
	return seq;
}

template<typename T>
void Quick(Sequence<T>* seq, Comp<T> func, size_t start, size_t end)
{
	int pivotIndex = start + (end - start) / 2;
	T pivot = seq->Get(pivotIndex);
	size_t leftIndex = start, rightIndex = end;

	for (size_t i = 0; i <= (end - start) / 2; i++)
	{
		while (!func(seq->Get(leftIndex), pivot) && leftIndex < pivotIndex)
		{
			leftIndex++;
		}

		while (!func(pivot, seq->Get(rightIndex)) && rightIndex > pivotIndex)
		{
			rightIndex--;
		}

		if (leftIndex == rightIndex)
		{
			break;
		}

		T item = seq->Get(leftIndex);
		seq->Get(leftIndex) = seq->Get(rightIndex);
		seq->Get(rightIndex) = item;

		if (leftIndex == pivotIndex) pivotIndex = rightIndex;
		else if (rightIndex == pivotIndex) pivotIndex = leftIndex;
	}

	if (pivotIndex > start) Quick(seq, func, start, pivotIndex - 1);
	if (pivotIndex < end) Quick(seq, func, pivotIndex + 1, end);
}

template<typename T>
Sequence<T>* QuickSort(Sequence<T>* seq, Comp<T> func)
{
	if (seq == nullptr)
	{
		return seq;
	}
	if (seq->GetLenght() != 0)
	{
		Quick(seq, func, 0, seq->GetLenght() - 1);
	}
	return seq;
}

#endif 