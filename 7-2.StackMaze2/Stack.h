#pragma once
#include <iostream>
#include <Windows.h>

#define FORCEINLINE __forceinline

// 최대 저장 수
constexpr int MAX_STACK_COUNT = 100;

template <typename T>
class Stack
{
public:
	explicit Stack() = default;
	~Stack() = default;

public:
	// 정리 함수
	void Clear()
	{
		memset(datas, 0, sizeof(datas));
		count = 0;
	}

	// 스택이 비었는지 확인
	FORCEINLINE bool IsEmpty() const { return count == 0; }

	// 스택이 가득 찼는지 확인
	FORCEINLINE bool IsFull() const { return count == MAX_STACK_COUNT; }

	// 스택에 데이터 추가
	bool Push(const T& data)
	{
		if (IsFull())
		{
			//MessageBoxA();
			std::cout << "스택이 가득차있어 추가가 불가능합니다.\n";
			return false;
		}

		// 전달된 경험치를 데이터에 저장
		datas[count] = data;
		++count;
		return false;
	}

	bool Push(T&& data)
	{
		if (IsFull())
		{
			std::cout << "스택이 가득차있어 추가가 불가능합니다.\n";
			return false;
		}

		// 전달된 경험치를 데이터에 저장
		datas[count] = std::move(data);
		++count;
		return false;
	}

	// 스택에서 데이터 추출
	bool Pop(T& outValue) 
	{
		if (IsEmpty())
		{
			std::cout << "스택이 비어있어 추가가 불가능합니다.\n";
			return false;
		}

		//--count;

		outValue = datas[--count];
		return true;
	}

public:
	FORCEINLINE int Count() const { return count; }

private:
	// 데이터 저장 공간
	T datas[MAX_STACK_COUNT];

	// 스택에 저장된 자료 수
	// = 데이터를 추가할 위치의 인덱스
	int count = 0;
};