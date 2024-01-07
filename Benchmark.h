#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <iostream>
#include <fstream>
#include <chrono>
#include "Sorting.h"
#include "Comparators.h"
#include "Smart_pointers\sequence_based\ArraySequence.h"

typedef bool(*Comp)(int, int);
typedef Sequence<int>* (*Sort)(Sequence<int>*, Comp);

void Benchmark();

#endif // !BENCHMARK_H