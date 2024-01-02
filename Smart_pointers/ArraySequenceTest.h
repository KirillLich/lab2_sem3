#ifndef ARRAY_SEQUENCE_TEST
#define ARRAY_SEQUENCE_TEST
#include "sequence_based/ArraySequence.h"
#include <assert.h>
#include <iostream>

class ArraySequenceTester
{
	int NumberOfTests = 3 + 4 + 5;
	int NumberOfPassedTests = 0;

	void TestConstructorArrayFromArray_1_5_3_4()
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

		NumberOfPassedTests++;
	}
	void TestConstructorEmptyArray()
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

		NumberOfPassedTests++;
	}
	void TestCopyConstructorArray_CopyOf_1_5_6_3_9()
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
		NumberOfPassedTests++;
	}
	void TestAllConstructorsArray()
	{
		this->TestConstructorArrayFromArray_1_5_3_4();
		this->TestConstructorEmptyArray();
		this->TestCopyConstructorArray_CopyOf_1_5_6_3_9();
	}

	void TestGetByIndexArray_1_5_6_3_9()
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

		NumberOfPassedTests++;
	}
	void TestGetSizeArray_1_5_6_3_9()
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

		NumberOfPassedTests++;
	}
	void TestGetFirstArray_1_5_6_3_9()
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
		NumberOfPassedTests++;
	}
	void TestGetLastArray_1_5_6_3_9()
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
		NumberOfPassedTests++;
	}
	void TestAllDecompositionsArray()
	{
		this->TestGetByIndexArray_1_5_6_3_9();
		this->TestGetSizeArray_1_5_6_3_9();
		this->TestGetFirstArray_1_5_6_3_9();
		this->TestGetLastArray_1_5_6_3_9();
	}

	void TestAppendEmptyArray()
	{
		int expectedNumber = 10;
		ArraySequence<int> arrayD;
		arrayD.Append(expectedNumber);

		assert(arrayD.Get(0) == expectedNumber);

		NumberOfPassedTests++;
	}
	void TestAppendArray_1_5_6_3_9()
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

		NumberOfPassedTests++;
	}
	void TestPrependEmptyArray()
	{
		int expectedNumber = 10;
		ArraySequence<int> arrayD;
		arrayD.Prepend(expectedNumber);

		assert(arrayD.Get(0) == expectedNumber);

		NumberOfPassedTests++;
	}
	void TestPrependArray_1_5_6_3_9()
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

		NumberOfPassedTests++;
	}
	void TestInsert_10Array_1_2_3To2()
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
		NumberOfPassedTests++;
	}
	void TestAllSetsInArray()
	{
		this->TestAppendEmptyArray();
		this->TestAppendArray_1_5_6_3_9();
		this->TestPrependEmptyArray();
		this->TestPrependArray_1_5_6_3_9();
		this->TestInsert_10Array_1_2_3To2();
	}

public:
	ArraySequenceTester() = default;

	void RunTests()
	{
		this->TestAllConstructorsArray();

		this->TestAllDecompositionsArray();

		this->TestAllSetsInArray();

		assert(NumberOfPassedTests == NumberOfTests);
	}
};


#endif