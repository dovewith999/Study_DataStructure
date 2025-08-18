#include "HashTable.h"	

// 해시 함수(Hash Function)
// 파라미터로 전달 받은 키를 활용해서 해시(숫자)를 생성하는 함수
int GenerateKey(const std::string& keyString)
{
	// 생성된 키 값
	int key = 0;

	for (int i = 0; i < static_cast<int>(keyString.length()); ++i)
	{
		// key += keyString[i] * (i + 1);	
		key = key * 31 + keyString[i]; // 31은 소수, 키 값이 커지면 충돌이 줄어듦
	}

	// 절대값으로 반환
	// 해시테이블에 저장을 위해서는 키 값이 인덱스로 반환되어야 하는데 인덱스는 음수가 될 수 없음
	// 고려하는 이유는 오버플로우로 인해 음수로 변환될 수 있기 때문
	return key < 0 ? key * -1 : key;
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

void HashTable::Add(const std::string& key, const std::string& value)
{
	// 키 생성
	int keyValue = GenerateKey(key);	

	// 키 값을 버킷 인덱스로 변환	
	int buketIndex = keyValue % bucketCount;	

	// 저장할 연결 리스트 가져오기
	LinkedList<Entry>& list = table[buketIndex];

	// 키가 같은 걸 허용할지? 허용하지 않을지?
	for (int i = 0; i < static_cast<int>(list.Count()); ++i)
	{
		// 키 중복을 허용하지 않음
		if (list[i]->data.key == key)
		{
			std::cout << "키가 중복되었습니다: " << key << '\n';
			return;
		}
	}

	// 해시 테이블에 값 추가
	list.PushLast(Entry(key, value));
}

void HashTable::Delete(const std::string& key)
{
	// 삭제 연산은 2단계의 복합 과정
	// 1. 찾기
	int keyValue = GenerateKey(key);	
	int buketIndex = keyValue % bucketCount;

	LinkedList<Entry>& list = table[buketIndex];
	for (int i = 0; i < static_cast<int>(list.Count()); ++i)
	{
		// 2. 삭제하기
		if (list[i]->data.key == key)
		{
			list.Delete(list[i]->data);
			std::cout << "키가 삭제되었습니다: " << key << '\n';
			return;
		}
	}

	std::cout << "키를 찾을 수 없습니다: " << key << '\n';	
	return;
}

bool HashTable::Find(const std::string& key, Entry& outValue)
{
	int keyValue = GenerateKey(key);

	// 버킷인덱스.
	int bucketIndex = keyValue % bucketCount;

	// 리스트 가져오기.
	LinkedList<Entry>& list = table[bucketIndex];

	// 검색할 필요가 있는지 확인.
	if (list.Count() == 0)
	{
		std::cout << "해당 키로 데이터를 검색하지 못했습니다.\n";
		return false;
	}

	// 검색.
	for (int ix = 0; ix < (int)list.Count(); ++ix)
	{
		// 같은 키를 가진 데이트를 찾았으면,
		if (list[ix]->data.key == key)
		{
			// 출력할 파라미터에 값 저장.
			outValue = list[ix]->data;

			// 검색 성공 반환.
			return true;
		}
	}

	std::cout << "해당 키로 데이터를 검색하지 못했습니다.\n";
	return false;
}

void HashTable::Print()
{
	for (int i = 0; i < bucketCount; ++i)
	{
		LinkedList<Entry>& list = table[i];

		if (list.Count() == 0)
		{
			continue;
		}

		for (int j = 0; j < static_cast<int>(table[i].Count()); ++j)
		{
			std::cout << "키: " << list[j]->data.key
				<< ", 값: " << list[j]->data.value << '\n';
		}
	}
}	

bool HashTable::IsEmpty() const
{
	int totalCount = 0;

	for (int i = 0; i < bucketCount; ++i)
	{
		totalCount += static_cast<int>(table[i].Count()); // 각 버킷의 항목 개수를 합산
	}

	return totalCount == 0; // 모든 버킷이 비어있으면 해시 테이블은 비어있음
}