#ifndef SORT_TESTER_H
#define SORT_TESTER_H
#include <assert.h>
#include "Sorting.h"
#include "Smart_pointers/sequence_based/ArraySequence.h"
#include "Comparators.h"

class SortTester
{
	using Sort = Sequence<int>* (*)(Sequence<int>*, Comp<int>);

	void EmptySequence(Sort func);
	void IntSequenceInDecreasingOrder(Sort func);
	void IntSequenceInIncreasingOrder(Sort func);

	void Bubble();

	void Insertion();

	void Quick();
public:
	SortTester() = default;
	void RunTests();
};

#endif // !SORT_TESTER_H