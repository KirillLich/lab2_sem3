#ifndef COMPARATORS_H
#define COMPARATORS_H

template<typename T>
bool CompIncreasingOrder(T first, T second)
{
	return first > second;
}

template<typename T>
bool CompDecreasingOrder(T first, T second)
{
	return first < second;
}

#endif // !COMPARATORS_H