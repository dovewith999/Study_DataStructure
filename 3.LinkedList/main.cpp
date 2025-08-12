#include "LinkedList.h"

int main()
{
	LinkedList list;
	
	list.Insert(10);
	list.Insert(50);
	list.Insert(30);
	list.Insert(20);

	list.Print();

	std::cin.get();
	return 0;
}