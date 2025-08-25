#include "QuadTree.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

QuadTree::QuadTree(const Bounds& bounds)
	: root(new Node(bounds))
{
}

QuadTree::~QuadTree()
{
	SafeDelete(root);
}

void QuadTree::Insert(Node* node)
{
	root->Insert(node);
}

std::vector<Node*> QuadTree::Query(Node* queryNode)
{
	// 겹침 가능성이 있는 영역 확인
	std::vector<Node*> possibleNodes;
	root->Query(queryNode->GetBounds(), possibleNodes);

	// 가능성이 있는 노드에서 실제로 겹치는 노드 검사.
	std::vector<Node*> intersects;

	//겹침 가능성이 있는 영역 순회
	for (Node* node : possibleNodes)
	{
		// 각 영역이 가지는 노드 순회
		for (Node* point : node->GetPoints())
		{
			// 겹침 검사
			if (point->GetBounds().Intersects(queryNode->GetBounds()))
			{
				intersects.emplace_back(point);
				continue;
			}
		}
	}

	// 최종 목록 반환
	// 노트 : 함수에서 출력용 배열을 참조로 받으면 최적화 가능
	return intersects;
}