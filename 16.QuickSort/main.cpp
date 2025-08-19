#include <iostream>
#include "QuickSort.h"	

#define ArraySize(array) (sizeof(array) / sizeof(array[0]))	

void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}

int main()
{
	// 자료 집합.
	int array[] =
	{
		1, 58, 10, 20, 56, 63, 73, 5, 28, 37,
		80, 61, 82, 45, 11, 66, 83, 59, 22, 64,
		52, 89, 94, 76, 44, 40, 75, 2, 23, 57,
		92, 8, 41, 96, 15, 84, 35, 69, 54, 47,
		90, 24, 43, 74, 34, 85, 72, 95, 18, 17,
		98, 9, 29, 53, 27, 79, 39, 51, 31, 16,
		6, 97, 26, 100, 21, 48, 33, 60, 91, 19,
		30, 13, 71, 78, 87, 25, 81, 4, 42, 93,
		49, 12, 14, 7, 62, 77, 38, 99, 88, 50,
		32, 46, 70, 3, 86, 68, 36, 67, 55, 65
	};

	auto length = ArraySize(array);

	// 정렬 전 출력.
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	QuickSort(array, 0, length - 1);

	std::cout << '\n';

	// 정렬 후 출력.
	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	std::cout << "퀵 정렬이 완료되었습니다.\n";

	std::cin.get();
	return 0;
}