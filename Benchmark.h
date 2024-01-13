#ifndef BENCHMARK_H
#define BENCHMARK_H
#include "Sorting.h"

using Sort = Sequence<int>* (*)(Sequence<int>*, Comp<int>);

void Benchmark();

#endif // !BENCHMARK_H