#pragma once
#include "Node.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

class LinkedList
{
public:
	explicit LinkedList();
	~LinkedList();

	// 첫 노드에 데이터 추가
	// 1. 노드가 비어있으면 Head 생성
	// 2. 노드가 있으면 Head 교체
	void AddToHead(int newData);

	// 맨 뒤에 노드 추가
	void Insert(int newData);

	// 노드 삭제
	void Delete(int data);

	// 버블 정렬을 이용한 정렬
	void Sort();

	// 출력
	void Print();

public:
	__forceinline int Count() const { return count; }

private:
	Node* head = nullptr;
	int count = 0;
};