#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
void SafeDelete(T*& target)
{
	if (target == nullptr)
	{
		return;
	}

	delete target;
	target = nullptr;
}

template<typename T>
class LinkedList
{
public:
	explicit LinkedList()
		: first(new Node<T>()), last(new Node<T>()), count(0)
	{	
		// 시작 노드 서로 연결
		first->next = last;
		last->previous = first;
	}

	~LinkedList()
	{
		// 노드 전부 제거
		Clear();

		// 기본 노드 삭제
		SafeDelete(first);
		SafeDelete(last);
	}

public:
	void Clear()
	{
		Node<T>* current = first->next;
		
		while (current != nullptr && current != last)
		{
			Node<T>* next = current->next;
			SafeDelete(current);
			current = next;
		}

		//정리 (처음 시작 상태로 되돌림)
		first->next = last;
		last->previous = first;
		count = 0;
	}

	// 마지막 위치에 노드 추가하는 함수
	void PushLast(const T& newData)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = newData;

		// 원래의 마지막 노드 임시 저장.
		// 이전 노드 관련 포인터 정리.
		Node<T>* previous = last->previous;
		previous->next = newNode;
		newNode->previous = previous;

		// 새로운 노드 관련 포인터 정리.
		newNode->next = last;
		last->previous = newNode;
		++count;
	}

	// 출력
	void Print()
	{
		Node<T>* current = first->next;
		while (current && current != last)
		{
			std::cout << "데이터: " << current->data << "\n";
			current = current->next;
		}
	}

private:
	// 처음과 마지막을 가리키는 노드
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;

	int count = 0;
};