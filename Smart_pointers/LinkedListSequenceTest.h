#ifndef LINKED_LIST_SEQUENCE_TEST
#define LINKED_LIST_SEQUENCE_TEST
#include "sequence_based/LinkedListSequence.h"
#include <assert.h>

class LinkedListSequenceTester
{
	int NumberOfTests = 2 + 4 + 5;
	int NumberOfPassedTests = 0;

	void TestConstructorEmptyLinkedList()
	{
		LinkedListSequence<int> listD;
		assert(listD.GetLenght() == 0);
		try
		{
			listD.Get(2);
			assert(!"is not empty");
		}
		catch (std::exception& e)
		{
			std::string s = e.what();
			assert(s == "EmptyList");
		}

		NumberOfPassedTests++;
	}
	void TestCopyConstructorLinkedList_CopyOf_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		LinkedListSequence<int> listDCopy(listD);
		assert(listDCopy.GetLenght() == listD.GetLenght());
		for (size_t i = 0; i < 5; i++)
		{
			assert(listD.Get(i) == listDCopy.Get(i));
		}
		NumberOfPassedTests++;
	}
	void TestAllConstructorsLinkedList()
	{
		this->TestConstructorEmptyLinkedList();
		this->TestCopyConstructorLinkedList_CopyOf_1_5_6_3_9();
	}

	void TestGetByIndexLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		assert(listD.Get(0) == 1);
		assert(listD.Get(1) == 5);
		assert(listD.Get(2) == 6);
		assert(listD.Get(3) == 3);
		assert(listD.Get(4) == 9);

		NumberOfPassedTests++;
	}
	void TestGetSizeLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		assert(listD.GetLenght() == 5);

		NumberOfPassedTests++;
	}
	void TestGetFirstLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		assert(listD.GetFirst() == 1);
		NumberOfPassedTests++;
	}
	void TestGetLastLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		assert(listD.GetLast() == 9);
		NumberOfPassedTests++;
	}
	void TestAllDecompositionsLinkedList()
	{
		this->TestGetByIndexLinkedList_1_5_6_3_9();
		this->TestGetSizeLinkedList_1_5_6_3_9();
		this->TestGetFirstLinkedList_1_5_6_3_9();
		this->TestGetLastLinkedList_1_5_6_3_9();
	}

	void TestAppendEmptyLinkedList()
	{
		LinkedListSequence<int> listD;
		listD.Append(10);

		assert(listD.Get(0) == 10);

		NumberOfPassedTests++;
	}
	void TestAppendLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		listD.Append(10);
		assert(listD.GetLenght() == 6);
		assert(listD.Get(5) == 10);

		NumberOfPassedTests++;
	}
	void TestPrependEmptyLinkedList()
	{
		LinkedListSequence<int> listD;
		listD.Prepend(10);

		assert(listD.Get(0) == 10);

		NumberOfPassedTests++;
	}
	void TestPrependLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 5; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		listD.Prepend(10);
		assert(listD.GetLenght() == 6);
		assert(listD.GetFirst() == 10);

		NumberOfPassedTests++;
	}
	void TestInsert_10LinkedList_1_2_3To2()
	{
		int* array = new int[3];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		LinkedListSequence<int> listD;
		for (size_t i = 0; i < 3; i++)
		{
			listD.Append(array[i]);
		}
		delete[] array;

		listD.InsertAt(10, 2);

		assert(listD.GetLenght() == 4);
		assert(listD.Get(0) == 1);
		assert(listD.Get(1) == 2);
		assert(listD.Get(2) == 10);
		assert(listD.Get(3) == 3);

		NumberOfPassedTests++;
	}
	void TestAllSetsInLinkedList()
	{
		this->TestAppendEmptyLinkedList();
		this->TestAppendLinkedList_1_5_6_3_9();
		this->TestPrependEmptyLinkedList();
		this->TestPrependLinkedList_1_5_6_3_9();
		this->TestInsert_10LinkedList_1_2_3To2();
	}

	
public:
	LinkedListSequenceTester()
	{


		this->TestAllConstructorsLinkedList();

		this->TestAllDecompositionsLinkedList();

		this->TestAllSetsInLinkedList();

		assert(NumberOfPassedTests == NumberOfTests);
	}
};

#endif