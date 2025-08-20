#include "String.h"
#include "Tree.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Tree<String> tree(static_cast<String>("A"));
	tree.AddChild(static_cast < String>("A"), static_cast < String>("B"));
	tree.AddChild(static_cast < String>("A"), static_cast < String>("C"));
	tree.AddChild(static_cast < String>("B"), static_cast < String>("D"));
	tree.AddChild(static_cast < String>("B"), static_cast < String>("E"));
	tree.AddChild(static_cast < String>("C"), static_cast < String>("F"));

	// 전위 순회
	tree.PreorderTraverse();

	std::cin.get();
	return 0;
}