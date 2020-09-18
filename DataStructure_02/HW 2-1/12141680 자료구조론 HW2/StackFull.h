#ifndef STACKFULL_H
#define STACKFULL_H // 헤더 파일 생성 시 반드시 선언

#include <string>
#include <string.h>

#include "RuntimeException.h"

class StackFull : public RuntimeException // StackFull 클래스 선언 (예외 클래스) // RuntimeException 클래스를 상속 받음
{
public :
	StackFull(const string &err) : RuntimeException(err) // 생성자 // 받아온 문구를 StackFull로 저장
	{
		cout << getMessage() << endl ; // 받아온 문구를 출력
	}
} ;

#endif