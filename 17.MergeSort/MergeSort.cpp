#include "MergeSort.h"
#include <iostream>

void Merge(int* array, int* leftArray, int leftArrayLength, int* rightArray, int rightArrayLength)
{
	int leftIndex = 0; // 왼쪽 배열 인덱스	
	int rightIndex = 0; // 오른쪽 배열 인덱스	
	int mergedIndex = 0; // 병합된 배열 인덱스	

	// 왼쪽/오른쪽 배열의 요소를 비교해 더 작은 배열의 요소를 array에 복사
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		// 크기 비교
		// 왼쪽이 선택되는 경우
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex; // 왼쪽 배열 인덱스 증가
		}

		// 오른쪽이 선택되는 경우
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex; // 오른쪽 배열 인덱스 증가
		}

		++mergedIndex; // 병합된 배열 인덱스 증가
	}

	// 남아있는 요소 병합
	while (leftIndex < leftArrayLength) 
	{
		array[mergedIndex] = leftArray[leftIndex];	
		++leftIndex; // 왼쪽 배열 인덱스 증가
		++mergedIndex; // 병합된 배열 인덱스 증가
	}

	while (rightIndex < rightArrayLength) 
	{
		array[mergedIndex] = rightArray[rightIndex];	
		++rightIndex; // 오른쪽 배열 인덱스 증가
		++mergedIndex; // 병합된 배열 인덱스 증가
	}
}

void MergeSort(int* array, int length)
{
	// 예외 처리
	if (length <= 1)
	{
		return;
	}

	// 배열 분할
	int mid = length >> 1; // 반으로 나눔

	// 분할될 두 배열의 공간 확보
	// 초기화하면 더 좋음
	int* leftArray = new int[mid]; // 왼쪽 배열	
	memset(leftArray, 0, sizeof(int) * mid);

	int* rightArray = new int[length - mid]; // 오른쪽 배열	
	memset(leftArray, 0, sizeof(int) * mid);

	// 값 복사
	//for (int i = 0; i < mid; ++i)
	//{
	//	leftArray[i] = array[i]; // 왼쪽 배열에 값 복사	
	//}
	memcpy(leftArray, array, sizeof(int) * mid); // 왼쪽 배열에 값 복사
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid)); // 오른쪽 배열에 값 복사

	// 왼쪽 배열에 대해 병합 정렬(재귀)
	MergeSort(leftArray, mid);

	// 오른쪽 배열에 대해 병합 정렬(재귀)
	MergeSort(rightArray, length - mid);

	// 병합
	Merge(array, leftArray, mid, rightArray, length - mid);

	// 메모리 정리
	delete[] leftArray;
	delete[] rightArray;
}
