#pragma once
#include "List.h"

template<typename T>
class Node
{
public:
	explicit Node()
		: data(), parent(nullptr)
	{
	}

	explicit Node(const T& data)
		: data(data), parent(nullptr)
	{
	}

	~Node()
	{
		parent = nullptr;
	}

public:
	void AddChild(Node<T>* child)
	{
		child->parent = this; // 자식 노드의 부모를 현재 노드로 설정

		children.PushBack(child); // 자식 노드를 리스트에 추가
	}

	void AddChild(const T& data)
	{
		AddChild(new Node<T>(data));
	}

	T GetData() const
	{
		return data; // 노드의 데이터를 반환
	}	

	const List<Node<T>*>& GetChildren() const
	{
		return children; // 자식 노드 리스트를 반환
	}	

	Node<T>* GetParent() const
	{
		return parent; // 부모 노드를 반환
	}

	void SetParent(const Node<T>* const newParent)
	{
		parent = newParent; // 부모 노드를 설정
	}	

private:
	Node(const Node& other) = delete; // 복사 생성자 금지
	Node(Node&& other) = delete; // 이동 생성자 금지

private:
	T data; // 노드 데이터

	Node<T>* parent = nullptr; // 부모 노드
	List<Node<T>*> children; // 자식 노드 리스트	
};