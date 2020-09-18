#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H // 헤더 파일 생성 시 반드시 선언

#include <iostream>
#include <string>
#include <string.h>

#include "ArrayStack.h"

using namespace std ;

class RuntimeException // RunTimeException 클래스 선언 (예외 클래스)
{
private :
	string errorMsg ;

public :
	RuntimeException(const string &err) // 생성자
	{
		errorMsg = err ; // 입력된 문구를 받아와 저장
	}

	string getMessage() const
	{
		return errorMsg ; // 받아와진 문구를 출력
	}
} ;

#endif