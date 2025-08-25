#pragma once
#include <vector>
#include "Node.h"

/*
*  쿼드 트리 클래스
*/

class QuadTree 
{
public:
	QuadTree(const Bounds& bounds);
	~QuadTree();

	// 트레이 노드를 추가하는 함수
	void Insert(Node* node);

	std::vector<Node*> Query(Node* queryNode);

public:
	// 나눌 수 있는 최대 깊이 값
	static const int maxDepth = 5;
private:
	Node* root = nullptr;
};