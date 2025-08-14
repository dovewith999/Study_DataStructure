#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	FILE* file = nullptr;

	fopen_s(&file, "../Test.txt", "rt");
	if (file == nullptr)
	{
		std::cout << "파일을 찾지 못했습니다.\n";
		return 0;
	}
	char buffer[2048];
	memset(buffer, 0, sizeof(buffer));
	fseek(file, 0, SEEK_SET);

	char* context = nullptr;
	fgets(buffer, 2048, file);

	LinkedList<int> list;

	char* data = strtok_s(buffer, " ", &context);

	while (true)
	{
		if (data == nullptr)
		{
			break;
		}

		list.PushLast(atoi(data));

		data = strtok_s(nullptr, " ", &context);
	}

	list.Print();

	// 삭제 테스트
	char input[50] = {};
	while (true)
	{
		std::cout << "삭제할 데이터를 입력해주세요(종료는 q)\n";
		std::cin >> input;

		// 입력 값이 q/Q 인지 확인.
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		// 예외처리(숫자만 입력 하도록 검증).
		if (!atoi(input))
		{
			std::cout << "숫자만 입력 가능합니다.\n";
			continue;
		}

		// 삭제.
		list.Delete(atoi(input));

		// 출력.
		list.Print();
	}

	std::cin.get();
	fclose(file);

	return 0;
}