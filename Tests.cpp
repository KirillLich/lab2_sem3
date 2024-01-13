#include "Tests.h"
#include "Smart_pointers\ArraySequenceTest.h"
#include "Smart_pointers\SmartPtrTester.h"
#include "SortTester.h"

void RunTests()
{
	ArraySequenceTester testArrayS;
	testArrayS.RunTests();
	SmrtPtrTester testPtr;
	testPtr.RunTests();
	SortTester testSortings;
	testSortings.RunTests();
}