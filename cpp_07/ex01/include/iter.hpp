# pragma once

template <typename ITER, typename FUNC>
void iter(ITER *array, int length, FUNC f)
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}