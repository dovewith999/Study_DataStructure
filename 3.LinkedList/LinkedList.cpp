#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
	: head(nullptr), count(0)
{
}

LinkedList::~LinkedList()
{
	// TODO : 삭제 로직 완성해야 함
}

void LinkedList::AddToHead(int newData)
{
	// 새로운 노드 생성.
	Node* newNode = new Node(newData);

	// Head가 비어있지 않은 경우
	// NewNode를 헤드로 만들어줘야 함
	if (head != nullptr)
	{
		newNode->next = head;
	}

	head = newNode;
	++count;
	return;
}

void LinkedList::Insert(int newData)
{
	// 새 노드 생성
	Node* newNode = new Node(newData);

	// List가 비어있는 경우
	if (head == nullptr)
	{
		head = newNode;
		++count;
		return;
	}
	// List가 비어있지 않은 경우
	Node* current = head;
	Node* trail = nullptr;

	while (current != nullptr)
	{
		trail = current;
		current = current->next;
	}

	trail->next = newNode;
	++count;
	return;
}

void LinkedList::Delete(int data)
{
	// TODO : 삭제 로직 구현해야 함
}

void LinkedList::Print()
{
	// 모든 노드 순회하면서 Data 출력
	Node* current = head;

	while (current != nullptr)
	{
		//현재 노드 데이터 출력
		std::cout << *current << '\n';

		// 다음 데이터 이동
		current = current->next;
	}
}
