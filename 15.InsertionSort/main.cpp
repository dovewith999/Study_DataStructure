#include <iostream>

#define ArraySize(array) sizeof(array) / sizeof(array[0])

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

void InsertionSort(int* array, int length)
{
	if (length <= 1)
	{
		return;
	}

	for (int i = 1; i < length; ++i)
	{
		// 키 추출
		int keyValue = array[i];
		int j = i - 1;

		// 들어갈 자리 찾기
		while (j >= 0 && array[j] > keyValue)
		{
			// 값 밀기
			array[j + 1] = array[j];
			--j;
		}

		// 키 삽입
		array[j + 1] = keyValue;
	}
}

int main()
{
	// 자료 집합
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 길이.
	int length = ArraySize(array);

	// 정렬 전 출력.
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	// 정렬.
	InsertionSort(array, length);

	// 정렬 후 출력.
	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	std::cin.get();

	return 0;
}