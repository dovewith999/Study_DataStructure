#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
	const int count = 30;
	Vector<int> vector;

	std::vector<int>::iterator vector2;

	for (int i = 0; i < count; ++i)
	{
		vector.PushBack(i + 1);
	}

	for (auto& item : vector)
	{
		std::cout << item << " ";
	}

	std::cout << '\n';

	std::cin.get();
	return 0;
}