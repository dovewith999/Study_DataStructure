#pragma once

#include <iostream>

//constexpr int MAX_QUEUE_SIZE = 100;
template<typename T, int Size = 10>
class Queue
{
public:
	explicit Queue()
		: front(0), rear(0), size(Size + 1)
	{
		memset(datas, 0, sizeof(T) * size);
	}

	~Queue() = default;

public:
	// 비었는지 확인
	bool IsEmpty() const
	{
		return front == rear;
	}
	// 가득 찼는지 확인
	bool IsFull() const
	{
		// rear의 다음 위치(1칸 차이)가 fonrt와 같으면 가득 찬 상태
		return (rear + 1) % size == front;
	}
	// 큐에 데이터 추가
	bool Enqueue(const T& newData)
	{
		if (IsFull())
		{
			std::cout << "큐가 가득 찼습니다.\n";
			return false;
		}

		//뒤에 데이터 추가
		rear = (rear + 1) % size;
		datas[rear] = newData;

		return true;
	}
	// 큐에서 데이터 추출
	bool Dequeue(T& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "큐가 비어있습니다.\n";
			return false;
		}

		// 앞에 있는 데이터 추출 
		front = (front + 1) % size;
		outValue = datas[front];

		//datas[front] = T();				    추출한 데이터 초기화 1
		//memset(&datas[front], 0, sizeof(T));  메모리 초기화 2	 
		memset(datas + front, 0, sizeof(T)); // 메모리 초기화	3	
		return true;
	}
	// 출력
	void Print() const
	{
		if (IsEmpty())
		{
			std::cout << "큐가 비어 있습니다.\n";
			return;
		}

		std::cout << "큐 내용: ";
		int max = front < rear ? rear : (rear + size);

		for (int i = front + 1; i < max; ++i)
		{
			std::cout << " " << datas[i % size]; // % 연산으로 인덱스가 MAX_QUEUE_SIZE를 넘어가지 않도록
		}

		std::cout << '\n';
	}

private:
	int front = 0;
	int rear = 0;
	int size = 0;
	T datas[Size + 1];
};