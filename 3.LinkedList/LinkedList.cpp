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

void LinkedList::Sort()
{
	if (head == nullptr || head->next == nullptr)
	{
		std::cout << "정렬할 노드가 부족합니다.\n";
		return;
	}

	
#pragma region 버블 정렬
	// [2]->[1]->[3]
	//bool swap = true;

	//while (swap)
	//{
	//	swap = false;
	//	Node* current = head; //[2]
	//	Node* next = current->next; // [1]
	//	Node* trail = nullptr;	

	//	while (next != nullptr)
	//	{
	//		if (current->data > next->data)
	//		{
	//			current->next = next->next; // [2]->[1] => [2]->[3]
	//			next->next = current; //[1]->[3] => [1]->[2]

	//			if (trail == nullptr)
	//			{
	//				head = next; // head = [2] => head = [1]
	//			}

	//			else
	//			{
	//				trail->next = next;
	//			}

	//			trail = next; // trail = nullptr => trail = [1]
	//			next = current->next; // next = [1] => next = [3]
	//			//current = trail->next; // current = [2] => current = [2]
	//			swap = true; // swap이 발생했으므로 다시 플래그를 true로
	//		}

	//		else
	//		{
	//			// 이미 정렬되어 있어 Swap이 발생하지 않음
	//			// [2]->[1]->[3]에서 [2]->[1]이 [1]->[2]가 되고 [2]->[3]을 swao을 검사하면 여기로 옴
	//			trail = current; // trail = [1] => trail = [2]
	//			current = next; // current = [2] => current = [3]
	//			next = next->next; // [3] 다음거랑 비교, 지금은 nullptr이므로 while문 종료
	//		}
	//	}
	//}
#pragma endregion


#pragma region 선택 정렬
	Node* currentNode = head;
	Node* minNode = currentNode; // 데이터 값이 가장 작은 노드
	Node* indexNode = nullptr; // 이 노드의 next로 minNode를 연결할 것, 그리고 insertNode를 minNode로 갱신 -> 이게 trailNode 역할

	int count = this->count;

	while (--count)
	{
		while (currentNode != nullptr) // 현재 리스트에서 가장 작은 노드를 검사
		{
			if (minNode->data > currentNode->data)
			{
				minNode = currentNode;
			}

			currentNode = currentNode->next;
		}

		if (indexNode == nullptr) // 첫 검사라면(제일 작은 값)
		{
			head->next = minNode->next;
			minNode->next = head;
			indexNode = minNode; // minnode의 ->next로 연결해야하므로
			head = indexNode;
		}

		else
		{
			minNode->next = indexNode->next;
			indexNode->next = minNode; // 이전에 연결된 노드의 next로 minNode를 연결
			indexNode = minNode; // insertNode를 minNode로 갱신
		}

		currentNode = indexNode->next;

		while (currentNode != nullptr)
		{
			if (currentNode->next == indexNode)
			{
				currentNode->next = minNode->next;
			}

			currentNode = currentNode->next;
		}

		minNode = indexNode->next; // 비교대상
	}
#pragma endregion
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
