#ifndef UI_H
#define UI_H
#include "..\Smart_pointers\sequence_based\ArraySequence.h"

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
	void PrintDialogMenu(const std::string dialogActions[], int n);

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

	ArraySequence<int>* MakeBaseArr();
	ArraySequence<int>* MakeRandomArr(size_t size);
	void UseArray();

public:
	UserInterface() = default;

	void ChooseStartAction();
};

#endif