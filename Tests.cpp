#include "Tests.h"

void RunTests()
{
	ArraySequenceTester testArrayS;
	testArrayS.RunTests();
	SmrtPtrTester testPtr;
	testPtr.RunTests();
	SortTester testSortings;
	testSortings.RunTests();
}