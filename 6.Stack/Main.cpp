#include "Stack.h"
#include <stack>

int main()
{
	Stack<float>stack;

	stack.Push(15.f);
	stack.Push(30.f);

	while (!stack.IsEmpty())
	{
		std::cout << stack.Pop() << '\n';
	}
	
	std::cin.get();
	return 0;
}