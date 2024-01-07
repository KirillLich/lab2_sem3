#ifndef LINKED_LIST_SEQUENCE_TEST
#define LINKED_LIST_SEQUENCE_TEST
#include "sequence_based/LinkedListSequence.h"
#include <assert.h>
#include <string>

class LinkedListSequenceTester
{
	int numberOfTests = 2 + 4 + 5;
	int numberOfPassedTests = 0;

	void EmptyConstructor()
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

		numberOfPassedTests++;
	}
	void CopyConstructor_1_5_6_3_9()
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
		numberOfPassedTests++;
	}
	void AllConstructors()
	{
		this->EmptyConstructor();
		this->CopyConstructor_1_5_6_3_9();
	}

	void GetByIndex_1_5_6_3_9()
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

		numberOfPassedTests++;
	}
	void GetSize_1_5_6_3_9()
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

		numberOfPassedTests++;
	}
	void GetFirst_1_5_6_3_9()
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
		numberOfPassedTests++;
	}
	void GetLast_1_5_6_3_9()
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
		numberOfPassedTests++;
	}
	void AllDecompositions()
	{
		this->GetByIndex_1_5_6_3_9();
		this->GetSize_1_5_6_3_9();
		this->GetFirst_1_5_6_3_9();
		this->GetLast_1_5_6_3_9();
	}

	void AppendToEmpty()
	{
		LinkedListSequence<int> listD;
		listD.Append(10);

		assert(listD.Get(0) == 10);

		numberOfPassedTests++;
	}
	void AppendTo_1_5_6_3_9()
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

		numberOfPassedTests++;
	}
	void PrependToEmpty()
	{
		LinkedListSequence<int> listD;
		listD.Prepend(10);

		assert(listD.Get(0) == 10);

		numberOfPassedTests++;
	}
	void PrependTo_1_5_6_3_9()
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

		numberOfPassedTests++;
	}
	void Insert_10In_1_2_3To2()
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

		numberOfPassedTests++;
	}
	void AllSets()
	{
		this->AppendToEmpty();
		this->AppendTo_1_5_6_3_9();
		this->PrependToEmpty();
		this->PrependTo_1_5_6_3_9();
		this->Insert_10In_1_2_3To2();
	}
	
public:
	LinkedListSequenceTester() = default;

	void RunTests()
	{
		this->AllConstructors();

		this->AllDecompositions();

		this->AllSets();

		assert(numberOfPassedTests == numberOfTests);
	}
};

#endif