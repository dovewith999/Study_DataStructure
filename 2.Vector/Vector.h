#pragma once

// 동적으로(실행 중에) 크기가 변하는 배열
// 템플릿은 같은 파일에 구현까지 해야함
// inl. 인라인 약자로 하는 한 클래스에서 템플릿을 전부 처리하면 파일이 너무 길어져서 inl 파일로 따로 처리를 했으나 최근에는 따로 안하고 그냥 템플릿은 하나의 파일로 처리
template<typename T>
class Vector
{
public:
	Vector()
		: size(0), capacity(2)
	{
		data = new T(capacity);
	}
	// RAII
	~Vector()
	{
		if (data)
		{
			delete data;
		}
	}

public:
	void PushBack(const T& value)
	{
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		//저장된 마지막 요소 다음 위치에 새로운 값 저장 후 크기 증가 처리
		data[size] = value;
		++size;
	}

	T& At(int index)
	{
		if (index >= size || index < 0)
		{
			__debugbreak();
		}

		return data[index];
	}

	void Set(int index, const T& value)
	{
		if (index >= size || index < 0)
		{
			__debugbreak();
		}

		data[index] = value;
	}

public: /*연산자 오버로딩*/
	// 접근 및 설정을 위한 인덱스 연산자 오버로딩
	T& operator[](int index)
	{
		if (index >= size || index < 0)
		{
			__debugbreak();
		}

		return data[index];
	}
	
	// 접근 및 설정을 위한 인덱스 연산자 오버로딩
	const T& operator[](int index) const
	{
		if (index >= size || index < 0)
		{
			__debugbreak();
		}

		return data[index];
	}

private:
	void ReAllocate(int newCapacity)
	{
		// TODO : 새로운 공간에 재할당 필요함
		// 1. 새로운 공간 할당
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);
		// 2. 기존 값 복사/이동
		//for (int i = 0; i < capacity; ++i)
		//{
		//	newBlock[i] = data[ix];
		//}
		memcpy(newBlock, data, sizeof(T) * capacity);
		// 3. 다 쓴 메모리 공간 해제 및 업데이트
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

	__forceinline T* Data() const { return data; }
	__forceinline int Size() const { return size; }
	__forceinline int Capacity() const { return capacity; }

private:
	T* data = nullptr; // 자료 컨테이너

	size_t size = 0; // 배열에 실제로 저장된 요소의 수
	size_t capacity = 0; // 미리 확보해둔 저장 공간의 크기
};