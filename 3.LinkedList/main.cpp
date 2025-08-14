#include "LinkedList.h"

#include <list> // 이중 연결 리스트
#include <forward_list> // 단일 연결 리스트

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/*LinkedList list;

	char input[50] = {};
	while (true)
	{
		std::cout << "추가할 데이터를 입력해주세요(종료는 q)\n";
		std::cin >> input;

		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		if (!atoi(input))
		{
			std::cout << "숫자만 입력 가능합니다.\n";
			continue;
		}

		list.Insert(atoi(input));
		list.Print();
	}

	while (true)
	{
		std::cout << "삭제할 데이터를 입력해주세요(종료는 q)\n";
		std::cin >> input;

		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		if (!atoi(input))
		{
			std::cout << "숫자만 입력 가능합니다.\n";
			continue;
		}

		list.Delete(atoi(input));
		list.Print();
	}

	std::cin.get();*/

	// 리스트 생성.
	LinkedList list;

	// 반복해서 입력 받기.
	char input[50] = {};

	// 데이터 추가 루프.
	while (true)
	{
		std::cout << "추가할 데이터를 입력해주세요(종료는 q)\n";
		std::cin >> input;

		// q를 눌렀는지 확인.
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		// 예외처리.
		if (!atoi(input))
		{
			std::cout << "숫자만 입력 가능합니다.\n";
			continue;
		}

		// 데이터 삽입.
		list.Insert(atoi(input));

		// 출력.
		list.Print();
	}

	list.Sort();
	list.Print();

	std::cin.get();

	return 0;
}