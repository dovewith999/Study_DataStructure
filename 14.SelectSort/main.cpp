#include <iostream>
#define ArraySize(array) sizeof(array) / sizeof(array[0])

void SelectSort(int* arr, int length)
{
	if (length < 1)
	{
		return;
	}
	
	for (int i = 0; i < length - 1; ++i)
	{
		int minIndex = i; // 현재 순회에서 가장 왼쪽 값

		for (int j = i + 1; j < length; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i) // min index 구하기
		{
			std::swap(arr[i], arr[minIndex]);
		}
	}
}

// 배열 출력 함수.
void PrintArray(int array[], int length)
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
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	int length = ArraySize(array);	

	std::cout << "정렬 잔 배열: ";
	PrintArray(array, length);
	
	SelectSort(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	//
	return 0;
}