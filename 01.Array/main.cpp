#include <iostream>
#include <array>

//배열 클래스
template<typename T, int size>
class Array
{
public:
	Array()
	{
		// 메모리 0으로 초기화
		memset(data, 0, sizeof(T) * size);
	}

	__forceinline int GetSize() const { return size; }
	// 연산자 오버로딩
	T& operator[](int index)
	{
		if (index < 0 || index > size - 1)
		{
			return data[0];
		}

		return data[index];
	}

private:
	T data[];
};

// 메인이 필요한 이유 : 실행용 파일이기 때문
// Application이기 때문에 main이 필요하다. Library는 필요 없다.  
int main()
{
	//// 배열 Array
	//int array[5] = { }; // 초기화 구문 1 : 자동으로 0, 포인터 타입이면 nullptr 등 기본 값? 채워준다.
	//memset(array, 0, sizeof(array)); // 초기화 구문 2 : 직관적으로 초기화하는 구문

	//// 동적 배열(Dynamic Array) 실행 중에 크기나 길이가 변경된다.
	//// 따라서 크기를 정할 때 변수를 넣을 수 있다.
	//int cnt = 5;
	//int* heepArray = new int[cnt] {};

	//delete[] heepArray;
	const int cnt = 20;
	Array<int, cnt> array;
	for (int i = 0; i < array.GetSize(); ++i)
		array[i] = i + 1;

	std::cin.get();

	return 0;
}