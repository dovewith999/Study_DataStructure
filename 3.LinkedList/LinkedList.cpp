#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
	: head(nullptr), count(0)
{
}

LinkedList::~LinkedList()
{
	// 노드 계산을 위한 변수 선언
	Node* current = head;
	Node* trail = nullptr;

	while (current != nullptr)
	{
		trail = current;
		current = current->next;
		delete trail;
		trail = nullptr;
		--count; // 디버깅 목적
	}
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
	//리스트가 비어 있으면 종료
	if (head == nullptr)
	{
		std::cout << "리스트가 비어 있어서 삭제가 불가능합니다.\n";
		return;
	}

	Node* current = head;
	Node* trail = nullptr;

	while (current != nullptr)
	{
		// 종료 조건 
		// 찾으려는 데이터를 가진 노드 검색에 성공한 경우
		if (current->data == data)
		{
			break;
		}

		// 못찾았으면 검색 이어감
		trail = current;
		current = current->next;
	}

	// 끝까지 순회했으나 값이 없는 경우
	if (current == nullptr)
	{
		std::cout << "값: " << data << "를 찾지 못했습니다.\n";
		return;
	}

	// 검색에 성공한 경우
	if (current == head)
	{
		head = head->next;
	}

	else
	{
		trail->next = current->next;
	}

	delete current;
	current = nullptr;
	--count;
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
