#include "String.h"
#include "Tree.h"
#include <iostream>

int main()
{
	Tree<String> tree(static_cast<String>("A"));
	tree.AddChild(static_cast < String>("A"), static_cast < String>("B"));
	tree.AddChild(static_cast < String>("A"), static_cast < String>("C"));
	tree.AddChild(static_cast < String>("B"), static_cast < String>("D"));
	tree.AddChild(static_cast < String>("B"), static_cast < String>("E"));
	tree.AddChild(static_cast < String>("C"), static_cast < String>("F"));


	return 0;
}