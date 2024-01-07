#ifndef ARRAY_SEQUENCE_TEST
#define ARRAY_SEQUENCE_TEST
#include "sequence_based/ArraySequence.h"
#include <assert.h>
#include <iostream>

class ArraySequenceTester
{
	int numberOfTests = 3 + 4 + 5;
	int numberOfPassedTests = 0;

	void ConstructorFrom_1_5_3_4()
	{
		const size_t arraySize = 4;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		assert(arrayD.GetLenght() == arraySize);
		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 5);

		numberOfPassedTests++;
	}
	void EmptyConstructor()
	{
		ArraySequence<int> arrayD;
		assert(arrayD.GetLenght() == 0);
		try
		{
			arrayD.Get(2);
			assert(!"is not empty");
		}
		catch (std::exception& e)
		{
			std::string s = e.what();
			assert(s == "IndexOutOfRange");
		}

		numberOfPassedTests++;
	}
	void CopyConstructor_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		ArraySequence<int> arrayDCopy(arrayD);
		assert(arrayDCopy.GetLenght() == arrayD.GetLenght());
		for (size_t i = 0; i < arraySize; i++)
		{
			assert(arrayD.Get(i) == arrayDCopy.Get(i));
		}
		numberOfPassedTests++;
	}
	void AllConstructors()
	{
		this->ConstructorFrom_1_5_3_4();
		this->EmptyConstructor();
		this->CopyConstructor_1_5_6_3_9();
	}

	void GetByIndex_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 5);
		assert(arrayD.Get(2) == 6);
		assert(arrayD.Get(3) == 3);
		assert(arrayD.Get(4) == 9);

		numberOfPassedTests++;
	}
	void GetSize_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		assert(arrayD.GetLenght() == arraySize);

		numberOfPassedTests++;
	}
	void GetFirst_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		assert(arrayD.GetFirst() == 1);
		numberOfPassedTests++;
	}
	void GetLast_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		assert(arrayD.GetLast() == 9);
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
		int expectedNumber = 10;
		ArraySequence<int> arrayD;
		arrayD.Append(expectedNumber);

		assert(arrayD.Get(0) == expectedNumber);

		numberOfPassedTests++;
	}
	void AppendTo_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		int expectedNumber = 10;
		arrayD.Append(expectedNumber);
		assert(arrayD.GetLenght() == arraySize + 1);
		assert(arrayD.Get(5) == expectedNumber);

		numberOfPassedTests++;
	}
	void PrependToEmpty()
	{
		int expectedNumber = 10;
		ArraySequence<int> arrayD;
		arrayD.Prepend(expectedNumber);

		assert(arrayD.Get(0) == expectedNumber);

		numberOfPassedTests++;
	}
	void PrependTo_1_5_6_3_9()
	{
		const size_t arraySize = 5;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, arraySize);
		delete[] array;

		int expectedNumber = 10;
		arrayD.Prepend(expectedNumber);
		assert(arrayD.GetLenght() == arraySize + 1);
		assert(arrayD.GetFirst() == expectedNumber);

		numberOfPassedTests++;
	}
	void Insert_10In_1_2_3To2()
	{
		const size_t arraySize = 3;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		ArraySequence<int> arrayD(array, arraySize);

		int expectedNumber = 10;
		arrayD.InsertAt(expectedNumber, 2);

		assert(arrayD.GetLenght() == arraySize + 1);
		assert(arrayD.Get(0) == array[0]);
		assert(arrayD.Get(1) == array[1]);
		assert(arrayD.Get(2) == expectedNumber);
		assert(arrayD.Get(3) == array[2]);

		delete[] array;
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
	ArraySequenceTester() = default;

	void RunTests()
	{
		this->AllConstructors();

		this->AllDecompositions();

		this->AllSets();

		assert(numberOfPassedTests == numberOfTests);
	}
};


#endif