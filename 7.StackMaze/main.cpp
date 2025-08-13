#include "Stack.h"

//2차원 좌표를 나타내는 클래스
class Vector2
{
public:
	explicit Vector2() = default;
	explicit Vector2(int x, int y)
		: x(x), y(y)
	{
	}
	~Vector2() = default;

public:
	//출력 편의를 위해 연산자 오버로딩
	friend std::ostream& operator<<(std::ostream& os, const Vector2 position)
	{
		return os << "(" << position.x << ", " << position.y << ")";
	}

public:
	int x = 0;
	int y = 0;
};

// 작은 맵.
constexpr size_t MAZE_SIZE = 6;
// map[y][x];
// s: 시작지점, g: 목표지점, 1: 벽, 0: 길
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1','1','1','1','1','1'},
	{'s','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','g'},
	{'1','1','1','1','1','1'}
};

// 가려는 위치가 이동 가능한지 확인하는 함수
// 입력은 행(y), 열(x)순서로
bool IsValidLocation(int y, int x)
{
	if (y >= MAZE_SIZE || x >= MAZE_SIZE || y < 0 || x < 0)
	{
		return false;
	}

	//확인
	return map[y][x] == '0' || map[y][x] == 'g';
}

int main()
{
	// 시작위치 검색
	int startX = 0;
	int startY = 0;

	for (int y = 0; y < MAZE_SIZE; ++y)
	{
		for (int x = 0; x < MAZE_SIZE; ++x)
		{
			std::cout << map[y][x] << " ";

			if (map[y][x] == 's')
			{
				startX = x;
				startY = y;
			}
		}

		std::cout << '\n';
	}

	// 시작 위치부터 탐색
	// 스택에 삽입
	Stack<Vector2> locationStack;
	locationStack.Push(Vector2(startX, startY));

	while (!locationStack.IsEmpty())
	{
		// 현재 위치 반환
		Vector2 currentLocation;
		locationStack.Pop(currentLocation);
		std::cout << currentLocation << " ";

		if (map[currentLocation.y][currentLocation.x] == 'g')
		{
			std::cout << "\n미로탐색종료\n";
			std::cin.get();
			return 0;
		}

		map[currentLocation.y][currentLocation.x] = '.';

		// 앞으로 이동할 위치를 stack에 삽입
		// 상
		if (IsValidLocation(currentLocation.y - 1, currentLocation.x))
		{
			locationStack.Push(Vector2(currentLocation.x, currentLocation.y - 1));
		}
		// 하 
		if (IsValidLocation(currentLocation.y + 1, currentLocation.x))
		{
			locationStack.Push(Vector2(currentLocation.x, currentLocation.y + 1));
		}
		//좌
		if (IsValidLocation(currentLocation.y, currentLocation.x - 1))
		{
			locationStack.Push(Vector2(currentLocation.x - 1, currentLocation.y));
		}
		//우
		if (IsValidLocation(currentLocation.y, currentLocation.x + 1))
		{
			locationStack.Push(Vector2(currentLocation.x + 1, currentLocation.y));
		}
	}

	std::cin.get();

	return 0;
}