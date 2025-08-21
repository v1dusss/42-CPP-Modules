# pragma once

template <typename T>
void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return a;
	return b;
}

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"