#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LinkedList<int> list;
	char input[50] = { };

	while (true)
	{
		std::cout << "추가할 데이터를 입력해주세요: ";
		std::cin >> input;

		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		if (!atoi(input))
		{
			std::cout << "숫자만 입력해주세요\n";
			continue;
		}

		list.PushLast(atoi(input));
		list.Print();
	}

	std::cin.get();
	return 0;
}