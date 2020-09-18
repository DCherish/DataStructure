#ifndef CHATSNS_H
#define CHATSNS_H

// 만약 CHATSNS.h 파일이 존재하지 않는다면 선언 (헤더 파일 작성 시 필수)
// 12141680 CSAdrs

#include <iostream>
#include <string>

using namespace std ;

#include "SNSADRS.h"

class CSAdrs : public SNSAdrs // 클래스를 상속 받음 (부모 클래스 : SNSAdrs, 자식 클래스 : CSAdrs)
{
private :
	string text ;
	int ccount ; // CSAdrs 클래스의 주소 개수

public :
	CSAdrs() {} ; // 생성자
	~CSAdrs() {} ; // 소멸자
	void howmanyadrs() ; // 현재 주소 개수 몇개 있는지를 출력 (부모 클래스에서 virtual function으로 선언)
	void sendmessage(int i) ; // overloading 함수(메소드), 변수 ; int 형
	void sendmessage(string s) ; // overloading 함수(메소드), 변수 ; string 형
} ;

void CSAdrs::howmanyadrs() // 현재 주소 개수 몇개 있는지 출력
{
	ccount = count ;

	cout << "The number of address : " << ccount << endl ;
}

void CSAdrs::sendmessage(int i) // 변수가 int형으로 받아와진다면 이 함수가 실행
{
	cout << "To. 010" << i << endl ;

	cout << "Enter a message : " << endl ;

	cin >> text ;

	cout << "message is sent successfully" << endl ;
}

void CSAdrs::sendmessage(string s) // 변수가 string형으로 받아와진다면 이 함수가 실행
{
	cout << "To. " << s << endl ;

	cout << "Enter a message : " << endl ;

	cin >> text ;

	cout << "message is sent successfully" << endl ;
}

#endif