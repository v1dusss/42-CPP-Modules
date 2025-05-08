# include "iter.hpp"
# include <iostream>

void printInt(int &i)
{
	std::cout << i << std::endl;
}

void setToZero(int &i)
{
	i = 0;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	std::cout << "Original int array:" << std::endl;
	iter(arr, 5, printInt);

	std::cout << "Setting int array to zero:" << std::endl;
	iter(arr, 5, setToZero);
	iter(arr, 5, printInt);

	return 0;
}