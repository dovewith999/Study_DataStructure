#pragma once

//Key 타입과 Value 타입을 템플릿으로 선언
template<typename Key, typename Value>
class TPair
{
public:
	explicit TPair()
		: key(), value()
	{
	}

	explicit TPair(const Key& key, const Value& value)
		: key(key), value(value)
	{
	}

	// 비교 연산자 오버로딩이 필수 (pair 2개를 비교할 수 있어야 함)
	bool operator==(const TPair<Key, Value>& other) const
	{
		return (key == other.key) && (value == other.value);
	}	

	bool operator!=(const TPair<Key, Value>& other) const
	{
		return (key != other.key) || (value != other.value);
		// 위의 코드와 동일한 의미
		//return !(*this == other);
	}

	bool operator<(const TPair<Key, Value>& other) const
	{
		return key < other.key;
	}	

	bool operator>(const TPair<Key, Value>& other) const
	{
		return key > other.key;
	}	

	bool operator<=(const TPair<Key, Value>& other) const
	{
		return key <= other.key;
	}

	bool operator>=(const TPair<Key, Value>& other) const
	{
		return key >= other.key;
	}

public:
	// 키 값
	Key key;

	// 밸류 값
	Value value;
};