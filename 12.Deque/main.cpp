#include "Deque.h"

int main()
{
	Deque<int, 10> deque;	
	for (int i = 1; i <= 10; ++i)
	{
		if (i % 2 == 0)
		{
			deque.AddFront(i);
		}

		else
		{
			deque.AddRear(i);
		}
	}

	deque.Print();

	std::cin.get();
	return 0;
}