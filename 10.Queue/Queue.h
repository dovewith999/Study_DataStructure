#pragma once

#include <iostream>

constexpr int MAX_QUEUE_SIZE = 100;	

class Queue
{
public:
	explicit Queue()
		: front(0), rear(0)
	{
		memset(datas, 0, sizeof(datas));
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
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}
	// 큐에 데이터 추가
	bool Enqueue(int newData)
	{
		if (IsFull())
		{
			std::cout << "큐가 가득 찼습니다.\n";
			return false;
		}

		//뒤에 데이터 추가
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		datas[rear] = newData;

		return true;
	}
	// 큐에서 데이터 추출
	bool Dequeue(int& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "큐가 비어있습니다.\n";
			return false;
		}	

		// 앞에 있는 데이터 추출 
		front = (front + 1) % MAX_QUEUE_SIZE;
		outValue = datas[front];

		datas[front] = 0; // 추출한 데이터는 0으로 초기화
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
		int max = front < rear ? rear : (rear + MAX_QUEUE_SIZE);

		for (int i = front + 1; i < max; ++i)
		{
			std::cout << " " << datas[i % MAX_QUEUE_SIZE]; // % 연산으로 인덱스가 MAX_QUEUE_SIZE를 넘어가지 않도록
		}

		std::cout << '\n';
	}

private:
	int front = 0;
	int rear = 0;
	int datas[MAX_QUEUE_SIZE] = { };
};