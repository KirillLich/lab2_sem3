#ifndef UI_H
#define UI_H
#include "..\Smart_pointers\sequence_based\ArraySequence.h"
#include "..\Sorting.h"
#include "..\Tests.h"
#include "..\Benchmark.h"

#include <chrono>
#include <algorithm>
#include <iostream>
#include <fstream>

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
		const std::size_t arraySize = 4;
		int* array = new int[arraySize];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		ArraySequence<int>* arrS = new ArraySequence<int>(array, arraySize);
		delete[] array;

		return arrS;
	}
	ArraySequence<int>* MakeRandomArr(size_t size)
	{
		int* array = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = rand() % 1000;
		}

		ArraySequence<int>* arrS = new ArraySequence<int>(array, size);
		delete[] array;

		return arrS;
	}
	void UseArray()
	{
		const std::size_t numberOfActions = 9;
		const std::string dialogActions[] = { "1. Exit", "2. Make new array", "3. Make random array", "4. Bubble sort increase order", "5. Insertion sort increase order", "6. Quick sort increase order", "7. Bubble sort decrease order", "8. Insertion sort decrease order", "9. Quick sort decrease order" };
		ArraySequence<int>* intArr = MakeBaseArr();
		bool exit = false;
		int newSize;
		int item;

		while (!exit)
		{
			PrintDialogMenu(dialogActions, numberOfActions);
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

public:
	UserInterface() = default;

	void ChooseStartAction()
	{
		const std::size_t numberOfActions = 4;
		const std::string dialogActions[] = { "1. Run tests", "2. Work with array", "3. Run time test", "4. Exit"};
		bool exit = false;
		while (!exit)
		{
			PrintDialogMenu(dialogActions, numberOfActions);
			switch (this->TakeItem<int>("Use numbers"))
			{
			case 1:
				RunTests();
				std::cout << "\n\tAll tests finished. No errors found.\n\n";
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
};

#endif