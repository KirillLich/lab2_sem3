#include "Benchmark.h"
#include <chrono>
#include <iostream>
#include <fstream>

#include "Comparators.h"
#include "Smart_pointers\sequence_based\ArraySequence.h"

void SingleBenchmark(Sort func, int* array, size_t size, int& result)
{
	ArraySequence<int>* arrayCopy = new ArraySequence<int>(array, size);

	auto startSort = std::chrono::high_resolution_clock::now();
	func(arrayCopy, CompIncreasingOrder);
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
	int averageResultBubble[resultsNumber] = { 0 };
	int averageResultInsertion[resultsNumber] = { 0 };
	int averageResultQuick[resultsNumber] = { 0 };
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

	std::ofstream fout;
	fout.open("benchmark.csv");
	fout << "Number of elements;" << "Bubble;" << "Insertion;" << "Quick" << std::endl;

	for (size_t i = 0; i < resultsNumber; i++)
	{
		averageResultBubble[i] /= iterationsNumber;
		averageResultInsertion[i] /= iterationsNumber;
		averageResultQuick[i] /= iterationsNumber;
		fout << (i + 1) * 1000 << "; " << averageResultBubble[i] << "; " << averageResultInsertion[i] << "; " << averageResultQuick[i] << std::endl;
	}

	fout.close();
}