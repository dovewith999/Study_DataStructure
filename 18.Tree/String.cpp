﻿#include "String.h"

String::String(const char* value)
{
	length = value == nullptr ? 0 : static_cast<int>(strlen(value));

    if (value == 0)
    {
        return;
    }

	data = new char[length + 1]; // 문자열 길이 + 널 문자 공간 확보
	strcpy_s(data, length + 1, value);
}

String::String(const String& other)
	: length(other.length)  
{
	data = new char[other.length + 1]; // 문자열 길이 + 널 문자 공간 확보
	strcpy_s(data, other.length + 1, other.data); // 문자열 복사
}

String::String(String&& other)
	: length(other.length), data(other.data) // 이동 생성자
{
	other.data = nullptr; // 이동 후 원본 객체의 data를 nullptr로 설정
}

String::~String()
{
    if (data != nullptr)
    {
	    delete[] data; // 동적 할당된 메모리 해제
    }
}

String& String::operator=(const String& other)
{
	length = other.length;

	data = new char[other.length + 1]; // 문자열 길이 + 널 문자 공간 확보   
	strcpy_s(data, other.length + 1, other.data); // 문자열 복사

	return* this; // 자기 자신을 반환	
}

String& String::operator=(String&& other)
{
	length = other.length;
	data = other.data; // 이동 후 원본 객체의 data를 가져옴
	other.data = nullptr; // 이동 후 원본 객체의 data를 nullptr로 설정

    return *this;// // 자기 자신을 반환
}

bool String::operator==(const String& other)
{
    return strcmp(data, other.data) == 0;
}

String String::operator+(const String& other)
{
    // 내 문자열과 파라미터로 전달된 문자열 합치기.

    // 두 문자열을 합친 문자 수 구하기.
    size_t newLength = length + other.length;

    // 저장 공간 확보.
    char* newString = new char[newLength + 1];

    // 내 문자열 복사.
    //strcpy_s(newString, length, data);
    memcpy(newString, data, length);

    // 파라미터로 전달된 문자열을 이어서 복사.
    //strcpy_s(newString + length, other.length + 1, other.data);
    //strcat_s(newString, newLength + 2, other.data);
    memcpy(newString + length, other.data, other.length);
    newString[newLength] = '\0';

    // 문자열 객체 생성.
    String temp(newString);
    delete[] newString;

    return temp;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << (str.data ? str.data : ""); // 문자열 출력, nullptr인 경우 빈 문자열 출력
}
