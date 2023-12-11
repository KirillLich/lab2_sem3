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
	int action;
	template<typename T>
	T takeItem(std::string errorMessage)
	{
		T out;
		std::cin >> out;
		if (!std::cin.good() || (std::cin.peek() != '\n'))
		{
			std::cin.clear();

			std::cout << errorMessage << '\n';
			while (std::cin.get() != '\n') {}
			out = this->takeItem<T>(errorMessage);
		}
		return out;
	}
	void printDialogMenu(const std::string dialogActions[], int n)
	{
		for (size_t i = 0; i < n; i++)
		{
			std::cout << dialogActions[i] << std::endl;
		}
	}

	template<typename T>
	void printSequence(Sequence<T>* seq)
	{
		std::cout << '[';
		for (size_t i = 0; i < seq->GetLenght(); i++)
		{
			std::cout << seq->Get(i);
			if (i != seq->GetLenght() - 1) std::cout << ", ";
		}
		std::cout << ']' << std::endl;
	}

	ArraySequence<int>* makeBaseArr()
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
	ArraySequence<int>* makeRandomArr(size_t size)
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
	void useArray()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new array", "3. Make random array", "4. Bubble sort increase order", "5. Insertion sort increase order", "6. Quick sort increase order", "7. Bubble sort decrease order", "8. Insertion sort decrease order", "9. Quick sort decrease order" };
		ArraySequence<int>* intArr = makeBaseArr();
		bool exit = false;
		int newSize;
		int position;
		int item;

		while (!exit)
		{
			printDialogMenu(dialogActions, 9);
			std::cout << "Started array: ";
			printSequence<int>(intArr);
			switch (this->takeItem<int>("Use numbers"))
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete intArr;
				intArr = new ArraySequence<int>;
				std::cout << "\nSet size for new array: ";
				newSize = this->takeItem<int>("Use numbers");
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
				newSize = this->takeItem<int>("Use numbers");
				intArr = makeRandomArr(newSize);
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

	void benchmark()
	{
		int count = 0;
		int averageResultBubble[10] = { 0,0,0,0,0,0,0,0,0,0 };
		int averageResultInsertion[10] = { 0,0,0,0,0,0,0,0,0,0 };
		int averageResultQuick[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (size_t n = 1; n <= 5; n++)
		{
			for (size_t i = 10 * 1000; i <= 20 * 1000; i += 1000)
			{

				int* array = new int[i];
				for (size_t j = 0; j < i; j++)
				{
					array[j] = rand() % 1000;
				}

				std::cout << "Test for " << i << " elements\n";

				ArraySequence<int>* intArr1 = new ArraySequence<int>(array, i);
				ArraySequence<int>* intArr2 = new ArraySequence<int>(array, i);
				ArraySequence<int>* intArr3 = new ArraySequence<int>(array, i);
				
				delete[] array;

				auto startBubbleSort = std::chrono::high_resolution_clock::now();
				BubbleSort(intArr1, CompIncreasingOrder);
				auto stopBubbleSort = std::chrono::high_resolution_clock::now();
				delete intArr1;
				auto durationBubble = std::chrono::duration_cast<std::chrono::milliseconds>(stopBubbleSort - startBubbleSort);

				std::cout << "Time taken by bubble sort: " << durationBubble.count() << " milliseconds" << std::endl;
				averageResultBubble[count] += (int)durationBubble.count();


				auto startInsertionSort = std::chrono::high_resolution_clock::now();
				InsertionSort(intArr2, CompIncreasingOrder);
				auto stopInsertionSort = std::chrono::high_resolution_clock::now();
				delete intArr2;
				auto durationInsertion = std::chrono::duration_cast<std::chrono::milliseconds>(stopInsertionSort - startInsertionSort);

				std::cout << "Time taken by insertion sort: " << durationInsertion.count() << " milliseconds" << std::endl;
				averageResultInsertion[count] += (int)durationInsertion.count();


				auto startQuickSort = std::chrono::high_resolution_clock::now();
				QuickSort(intArr3, CompIncreasingOrder);
				auto stopQuickSort = std::chrono::high_resolution_clock::now();
				delete intArr3;
				auto durationQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stopQuickSort - startQuickSort);

				std::cout << "Time taken by quick sort: " << durationQuick.count() << " milliseconds" << std::endl;
				averageResultQuick[count] += (int)durationQuick.count();


				count++;
			}
			count = 0;
		}
		for (size_t i = 0; i < 10; i++)
		{
			averageResultBubble[i] /= 5;
			averageResultInsertion[i] /= 5;
			averageResultQuick[i] /= 5;
			std::cout << "For 10^" << i + 1 << " elements\n";
			std::cout << "Average time taken by bubble sort: " << averageResultBubble[i] << " milliseconds" << std::endl;
			std::cout << "Average time taken by insertion sort: " << averageResultInsertion[i] << " milliseconds" << std::endl;
			std::cout << "Average time taken by quick sort: " << averageResultQuick[i] << " milliseconds" << std::endl;
		}
	}

	void chooseStartAction(bool &exit)
	{
		const std::string dialogActions[] = { "1. Run tests", "2. Work with array", "3. Run time test", "4. Exit"};
		printDialogMenu(dialogActions, 4);
		switch (this->takeItem<int>("Use numbers"))
		{
		case 1:
			runTests();
			break;
		case 2:
			useArray();
			break;
		case 3:
			benchmark();
			break;
		case 4:
			exit = true;
			break;
		default:
			std::cout << "Use number from 1 to 7\n";
			break;
		}
	}

	void runTests()
	{
		ArraySequenceTester testArrayS;
		SmrtPtrTester testPtr;
		SortTester testSortings;
		testPtr.RunTests();
		std::cout << "\n\tAll tests finished. No errors found.\n\n";
	}

public:
	UserInterface()
	{
		bool exit = false;
		while(!exit) chooseStartAction(exit);
	}
};

#endif