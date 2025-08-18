#pragma once
#include <iostream>
#include <string>
#include "Pair.h"
#include "LinkedList.h"	

// HashTable 클래스 정의	
class HashTable
{
private:
	using Entry = TPair<std::string, std::string>; // 키와 값을 저장할 Pair 타입 정의

public:
	explicit HashTable();
	~HashTable();

public:
	// 해시 테이블에 키-값 쌍 추가
	void Add(const std::string& key, const std::string& value);
	
	// 해시 테이블에서 키-값 쌍 삭제
	void Delete(const std::string& key);
	
	// 해시 테이블에서 키로 값 검색
	bool Find(const std::string& key, Entry& outValue);

	// 해시 테이블의 모든 항목 출력
	void Print();	

	// 해시 테이블이 비었는지 확인
	bool IsEmpty() const;

private:
	// 버킷(Bucket) 정의
	static const int bucketCount = 19; // 해시 테이블의 버킷 개수, 소수를 써야지 충돌이 적, 크면 클 수록 좋음

	// 체이닝 기법을 사용해 각 버킷에 저장할 엔트리의 연결 리스트
	LinkedList<Entry> table[bucketCount]; // 버킷 배열
};