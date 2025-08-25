#include <iostream>
#include "QuadTree.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	QuadTree tree(Bounds(0, 0, 100.0f, 100.0f));

	// 삽입
	tree.Insert(new Node(Bounds(40.0f, 40.0f, 20.0f, 20.0f)));
	tree.Insert(new Node(Bounds(20.0f, 20.0f, 2.0f, 2.0f)));

	//쿼리
	Node testNode(Bounds(50, 50, 5, 5));
	std::vector<Node*> intersects = tree.Query(&testNode);

	if (intersects.size() == 0)
	{
		std::cout << "검색 실패 \n";
	}
	
	else
	{
		std::cout << "겹치는 노드들 " << intersects.size() << "개 찾았습니다.\n";
	}

	return 0;
}