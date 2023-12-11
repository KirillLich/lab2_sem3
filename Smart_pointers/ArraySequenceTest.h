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
		int* array = new int[4];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		ArraySequence<int> arrayD(array, 4);
		delete[] array;

		assert(arrayD.GetLenght() == 4);
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
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
		delete[] array;

		ArraySequence<int> arrayDCopy(arrayD);
		assert(arrayDCopy.GetLenght() == arrayD.GetLenght());
		for (size_t i = 0; i < 5; i++)
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
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
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
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
		delete[] array;

		assert(arrayD.GetLenght() == 5);

		NumberOfPassedTests++;
	}
	void TestGetFirstArray_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
		delete[] array;

		assert(arrayD.GetFirst() == 1);
		NumberOfPassedTests++;
	}
	void TestGetLastArray_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
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
		ArraySequence<int> arrayD;
		arrayD.Append(10);

		assert(arrayD.Get(0) == 10);

		NumberOfPassedTests++;
	}
	void TestAppendArray_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
		delete[] array;

		arrayD.Append(10);
		assert(arrayD.GetLenght() == 6);
		assert(arrayD.Get(5) == 10);

		NumberOfPassedTests++;
	}
	void TestPrependEmptyArray()
	{
		ArraySequence<int> arrayD;
		arrayD.Prepend(10);

		assert(arrayD.Get(0) == 10);

		NumberOfPassedTests++;
	}
	void TestPrependArray_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		ArraySequence<int> arrayD(array, 5);
		delete[] array;

		arrayD.Prepend(10);
		assert(arrayD.GetLenght() == 6);
		assert(arrayD.GetFirst() == 10);

		NumberOfPassedTests++;
	}
	void TestInsert_10Array_1_2_3To2()
	{
		int* array = new int[3];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		ArraySequence<int> arrayD(array, 3);
		delete[] array;

		arrayD.InsertAt(10, 2);

		assert(arrayD.GetLenght() == 4);
		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 2);
		assert(arrayD.Get(2) == 10);
		assert(arrayD.Get(3) == 3);

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
	ArraySequenceTester()
	{
		this->TestAllConstructorsArray();

		this->TestAllDecompositionsArray();

		this->TestAllSetsInArray();

		assert(NumberOfPassedTests == NumberOfTests);
	}
};


#endif