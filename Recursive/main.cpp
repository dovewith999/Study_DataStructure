#include <iostream>

int BinarySearch(int array[], int target, int low, int high)
{
	// [1, 2, 3, 4, 5, 6, 7, 8, 9]
	// mid = 5
	// [1, 2, 3, 4] / [6, 7, 8, 9]
	// target > mid? target < mid?
	// target == array[mid] 
	
	// 검색 실패
	if (low > high)
	{
		return -1;
	}

	int mid = (low + high) >> 1;

	// 탐색 성공
	if (array[mid] == target)
	{
		return mid;
	}

	//오른쪽 먼저 탐색
	else if (array[mid] < target)
	{
		return BinarySearch(array, target, mid + 1, high);
	}

	// 왼쪽 탐색
	else
	{
		return BinarySearch(array, target, low, mid - 1);
	}
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int lenght = sizeof(array) / sizeof(array[0]);

	int result = BinarySearch(array, 7, 0, lenght);

	if (result < 0)
	{
		std::cout << "검색 실패\n";
	}

	else
	{
		std::cout << "검색 성공: " << result << "번 인덱스\n";
	}

	return 0;
}