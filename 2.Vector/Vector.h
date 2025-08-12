#pragma once

template<typename Vector>
class VectorIterator
{
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType ptr)
		: ptr(ptr)
	{
	}

	VectorIterator& operator++()
	{
		++ptr;
		return *this;
	}

	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	VectorIterator& operator--()
	{
		ptr--;
		return *this;
	}

	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	ReferenceType operator[](int index)
	{
		return *(ptr + index);
	}

	PointerType operator->()
	{
		return ptr;
	}

	ReferenceType operator*()
	{
		return *ptr;
	}

	bool operator==(const VectorIterator& other) const
	{
		return ptr == other.ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}

private:
	PointerType ptr;
};


// 동적으로(실행 중에) 크기가 변하는 배열
// 템플릿은 같은 파일에 구현까지 해야함
// inl. 인라인 약자로 하는 한 클래스에서 템플릿을 전부 처리하면 파일이 너무 길어져서 inl 파일로 따로 처리를 했으나 최근에는 따로 안하고 그냥 템플릿은 하나의 파일로 처리
template<typename T>
class Vector
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T>>;

public:
	Vector()
	{
		// allocate 2 elements.
		Reallocate(2);
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
			Reallocate(capacity * 2);
		}

		//저장된 마지막 요소 다음 위치에 새로운 값 저장 후 크기 증가 처리
		data[size] = value;
		++size;
	}

	// RValue Reference
	void PushBack(T&& value)
	{
		if (size == capacity)
		{
			Reallocate(capacity * 2);
		}

		// 핵심. Move Semantic
		data[size] = std::move(value);
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

	Iterator begin()
	{
		return Iterator(data);
	}

	Iterator end()
	{
		return Iterator(data + size);
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
	void Reallocate(size_t newCapacity)
	{
		// 1. allocate a new block of memory.
		T* newBlock = new T[newCapacity];

		// when vector is downsizing we need to check if new capacity is less than size.
		// in this case vector could be overflow.
		if (newCapacity < size)
		{
			size = newCapacity;
		}

		// 2. copy/move ole elements into new block.
		for (size_t ix = 0; ix < size; ++ix)
		{
			//newBlock[ix] = data[ix];
			newBlock[ix] = std::move(data[ix]);
		}

		// 3. delete
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