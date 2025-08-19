#pragma once
#include <iostream>

class String
{
public:
	explicit String(const char* value = nullptr);
	String(const String& other);
	String(String&& other);
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other);
	bool operator==(const String& other);
	String operator+(const String& other);

	friend std::ostream& operator<<(std::ostream& os, const String& str);

private:
	int length = 0; // 문자열 길이	
	char* data = nullptr; // 문자열 데이터
};