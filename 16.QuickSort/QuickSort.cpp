#include "QuickSort.h"
#include <algorithm>

int Partition(int* array, int left, int right)
{
    // 피벗을 기준으로 배열을 분할
	int pivot = array[left]; // 첫 번째 요소를 피벗으로 선택  
	int low = left + 1; // 왼쪽 인덱스
	int high = right; // 오른쪽 인덱스

    while (low <= high)
    {
		// 왼쪽 인덱스에서 피벗보다 큰 값을 찾음
        while (low <= right && array[low] <= pivot)
        {
            ++low;
        }

		// 오른쪽 인덱스에서 피벗보다 작은 값을 찾음
        while (high > left && array[high] >= pivot)
        {
			--high; 
        }
        // 종료 조건 확인
		// low가 high보다 크면 종료
        if (low > high)
        {
            break;
		}

        // low와 high가 교차하지 않으면 두 값을 교환
        std::swap(array[low], array[high]);
    }

	// 피벗 값과 high 위치의 값을 교환하여 피벗을 올바른 위치에 놓음
	std::swap(array[left], array[high]);

    // 왼쪽 집합의 마지막 인덱스를 반환
    return high;
}

void QuickSort(int* array, int left, int right)
{
    // 예외 처리
	// 왼쪽 인덱스와 오른쪽 인덱스가 교차하면 정렬할 필요 없음
    if (left >= right)
    {
        return;
    }

    // 피벗을 기준으로 배열 분할
	int pivot = Partition(array, left, right);

    // 왼쪽 배열 정렬(재귀)
	QuickSort(array, left, pivot - 1);

	// 오른쪽 배열 정렬(재귀)    
	QuickSort(array, pivot + 1, right);
}
