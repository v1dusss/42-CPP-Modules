# pragma once

template <typename ITER, typename FUNC>
void iter(ITER *array, int length, FUNC f)
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"