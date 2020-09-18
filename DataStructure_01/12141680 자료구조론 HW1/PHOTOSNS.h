#ifndef PHOTOSNS_H
#define PHOTOSNS_H

// 만약 PHOTOSNS.h 파일이 존재하지 않는다면 선언 (헤더 파일 작성 시 필수)
// 12141680 PSAdrs

#include <iostream>

using namespace std ;

#include "SNSADRS.h"
#include "UPLOADSNS.h"

class PSAdrs : public USAdrs // 클래스를 상속 받음 (부모 클래스 : USAdrs, 자식 클래스 : PSAdrs)
{
public :
	PSAdrs() {} ; // 생성자
	~PSAdrs() {} ; // 소멸자

	template <typename T> // template
	void Hashtag(T a) ;
} ;

template <typename T>
void PSAdrs::Hashtag(T a) // 입력받을 변수 형에 따라서 다른 내용이 출력
{
	if( sizeof(a) == 4 ) // 만약 int형이라면 sizeof(a) = 4byte가 되어 이 내용이 출력
	{
		cout << "#" << a << "♡" << endl ;
	}else // 4byte가 아니라면 이 내용으로 출력
	{
		cout << "#" << a << "♥" << endl ;
	}
}

#endif