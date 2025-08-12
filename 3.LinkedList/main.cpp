#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LinkedList list;
	
	list.Insert(10);
	list.Insert(50);
	list.Insert(30);
	list.Insert(20);

	list.Print();

	list.Delete(100);
	list.Delete(30);
	list.Delete(50);

	std::cin.get();
	return 0;
}