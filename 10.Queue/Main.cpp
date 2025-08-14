#include "Queue.h"

int main()
{
	Queue queue;

	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i + 1);
	}

	queue.Print();

	int value = 0;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Print();

	std::cin.get();
	return 0;
}