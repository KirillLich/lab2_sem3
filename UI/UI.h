#ifndef UI_H
#define UI_H
#include "..\Smart_pointers\sequence_based\ArraySequence.h"
#include "..\Smart_pointers\ArraySequenceTest.h"
#include "..\Smart_pointers\SmartPtrTester.h"
#include "..\Sorting.h"
#include "..\SortTester.h"
#include <chrono>
#include <algorithm>
#include <iostream>

class UserInterface
{
	template<typename T>
	T TakeItem(std::string errorMessage)
	{
		T out;
		std::cin >> out;
		if (!std::cin.good() || (std::cin.peek() != '\n'))
		{
			std::cin.clear();

			std::cout << errorMessage << '\n';
			while (std::cin.get() != '\n') {}
			out = this->TakeItem<T>(errorMessage);
		}
		return out;
	}
	void PrintDialogMenu(const std::string dialogActions[], int n)
	{
		for (size_t i = 0; i < n; i++)
		{
			std::cout << dialogActions[i] << std::endl;
		}
	}

	template<typename T>
	void PrintSequence(Sequence<T>* seq)
	{
		std::cout << '[';
		for (size_t i = 0; i < seq->GetLenght(); i++)
		{
			std::cout << seq->Get(i);
			if (i != seq->GetLenght() - 1) std::cout << ", ";
		}
		std::cout << ']' << std::endl;
	}

	ArraySequence<int>* MakeBaseArr()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		ArraySequence<int>* arr = new ArraySequence<int>(array, 4);
		delete[] array;

		return arr;
	}
	ArraySequence<int>* MakeRandomArr(size_t size)
	{
		int* array = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = rand() % 1000;
		}

		ArraySequence<int>* arr = new ArraySequence<int>(array, size);
		delete[] array;

		return arr;
	}
	void UseArray()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new array", "3. Make random array", "4. Bubble sort increase order", "5. Insertion sort increase order", "6. Quick sort increase order", "7. Bubble sort decrease order", "8. Insertion sort decrease order", "9. Quick sort decrease order" };
		ArraySequence<int>* intArr = MakeBaseArr();
		bool exit = false;
		int newSize;
		int position;
		int item;

		while (!exit)
		{
			PrintDialogMenu(dialogActions, 9);
			std::cout << "Started array: ";
			PrintSequence<int>(intArr);
			switch (this->TakeItem<int>("Use numbers"))
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete intArr;
				intArr = new ArraySequence<int>;
				std::cout << "\nSet size for new array: ";
				newSize = this->TakeItem<int>("Use numbers");
				std::cout << "\nWrite " << newSize << " elements of array.\n";
				for (size_t i = 0; i < newSize; i++)
				{
					std::cin >> item;
					intArr->Append(item);
				}
				newSize = 0;
				break;
			case 3:
				delete intArr;
				std::cout << "\nSet size for new array: ";
				newSize = this->TakeItem<int>("Use numbers");
				intArr = MakeRandomArr(newSize);
				newSize = 0;
				break;
			case 4:
				BubbleSort(intArr, CompIncreasingOrder);
				break;
			case 5:
				InsertionSort(intArr, CompIncreasingOrder);
				break;
			case 6:
				QuickSort(intArr, CompIncreasingOrder);
				break;
			case 7:
				BubbleSort(intArr, CompDecreasingOrder);
				break;
			case 8:
				InsertionSort(intArr, CompDecreasingOrder);
				break;
			case 9:
				QuickSort(intArr, CompDecreasingOrder);
				break;
			default:
				std::cout << "Use numbers from 1 to 4\n";
				break;
			}
		}
		delete intArr;
	}

	typedef int(*comp)(int, int);
	typedef Sequence<int>* (*SortingFunction)(Sequence<int>*, comp);

	void SingleBenchmark(SortingFunction sortingFunction, int* array, size_t size, int& result)
	{
		ArraySequence<int>* arrayCopy = new ArraySequence<int>(array, size);

		auto startSort = std::chrono::high_resolution_clock::now();
		sortingFunction(arrayCopy, CompIncreasingOrder);
		auto stopSort = std::chrono::high_resolution_clock::now();
		delete arrayCopy;
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopSort - startSort);

		result += (int)duration.count();
	}

	void Benchmark()
	{
		const int iterationsNumber = 5;
		const int step = 1000;
		const int minNumberOfElements = 1000;
		const int maxNumberOfElements = 19 * 1000;
		const int resultsNumber = (maxNumberOfElements - minNumberOfElements) / step + 1;


		int count = 0;
		int averageResultBubble[resultsNumber] = {0};
		int averageResultInsertion[resultsNumber] = {0};
		int averageResultQuick[resultsNumber] = {0};
		for (size_t n = 1; n <= iterationsNumber; n++)
		{
			for (size_t numberOfElements = minNumberOfElements; numberOfElements <= maxNumberOfElements; numberOfElements += step)
			{

				int* array = new int[numberOfElements];
				for (size_t j = 0; j < numberOfElements; j++)
				{
					array[j] = rand() % 1000;
				}

				std::cout << "Test for " << numberOfElements << " elements\n";

				SingleBenchmark(BubbleSort, array, numberOfElements, averageResultBubble[count]);
				SingleBenchmark(InsertionSort, array, numberOfElements, averageResultInsertion[count]);
				SingleBenchmark(QuickSort, array, numberOfElements, averageResultQuick[count]);
				delete[] array;
				count++;
			}
			count = 0;
		}
		for (size_t i = 0; i < resultsNumber; i++)
		{
			averageResultBubble[i] /= iterationsNumber;
			averageResultInsertion[i] /= iterationsNumber;
			averageResultQuick[i] /= iterationsNumber;
			std::cout << "For 1000 * " << i + 1 << " elements\n";
			std::cout << "Average time taken by bubble sort: " << averageResultBubble[i] << " milliseconds" << std::endl;
			std::cout << "Average time taken by insertion sort: " << averageResultInsertion[i] << " milliseconds" << std::endl;
			std::cout << "Average time taken by quick sort: " << averageResultQuick[i] << " milliseconds" << std::endl;
		}
	}

	void ChooseStartAction()
	{
		const std::string dialogActions[] = { "1. Run tests", "2. Work with array", "3. Run time test", "4. Exit"};
		bool exit = false;
		while (!exit)
		{
			PrintDialogMenu(dialogActions, 4);
			switch (this->TakeItem<int>("Use numbers"))
			{
			case 1:
				RunTests();
				break;
			case 2:
				UseArray();
				break;
			case 3:
				Benchmark();
				break;
			case 4:
				exit = true;
				break;
			default:
				std::cout << "Use number from 1 to 7\n";
				break;
			}
		}
	}

	void RunTests()
	{
		ArraySequenceTester testArrayS;
		testArrayS.RunTests();
		SmrtPtrTester testPtr;
		testPtr.RunTests();
		SortTester testSortings;
		testSortings.RunTests();
		std::cout << "\n\tAll tests finished. No errors found.\n\n";
	}

public:
	UserInterface()
	{
		ChooseStartAction();
	}
};

#endif