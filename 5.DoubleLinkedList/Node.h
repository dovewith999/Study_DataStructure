#pragma once

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList;

private:
	explicit Node() : data()/*이렇게 하면 타입에 따라 자동으로 초기화 됨*/, next(nullptr), previous(nullptr)
	{
	}

private:
	T data /*= default(T)*/; // 템플릿 변수 초기화

	Node<T>* next = nullptr;
	Node<T>* previous = nullptr;
};