#include <iostream>

void Sort(int* array, int length)
{
    // 버블 정렬 (오름 차순).
    for (int ix = 0; ix < length - 1; ++ix)
    {
        for (int jx = 0; jx < length - 1 - ix; ++jx)
        {
            // 두 수 비교.
            if (array[jx] > array[jx + 1])
            {
                // 교환.
                std::swap(array[jx], array[jx + 1]);
            }
        }
    }
}

// 출력 함수.
void PrintArray(int* array, int length)
{
    for (int ix = 0; ix < length; ++ix)
    {
        std::cout << array[ix];

        // 마지막은 콤마 안넣기.
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
    int array[] = { 5, 2, 8, 4, 1 };

    // 배열 길이.
    int length = sizeof(array) / sizeof(array[0]);

    std::cout << "정렬 전: ";
    PrintArray(array, length);

    // 정렬.
    Sort(array, length);

    std::cout << "정렬 후: ";
    PrintArray(array, length);

    std::cin.get();

	return 0;
}