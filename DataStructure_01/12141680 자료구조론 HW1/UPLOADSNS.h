#ifndef UPLOADSNS_H
#define UPLOADSNS_H

// 만약 UPLOADSNS.h 파일이 존재하지 않는다면 선언 (헤더 파일 작성 시 필수)
// 12141680 USAdrs

#include <iostream>
#include <string>

using namespace std ;

#include "SNSADRS.h"

class USAdrs : public SNSAdrs // 클래스를 상속 받음 (부모 클래스 : SNSAdrs, 자식 클래스 : USAdrs)
{
private :
	string news[10] ;
	int ucount ;
	int scount ;

public :
	USAdrs() ; // 생성자
	virtual ~USAdrs() {} ; // virtual destructor
	void howmanyadrs() ; // 현재 주소 개수 몇개 있는지를 출력 (부모 클래스에서 virtual function으로 선언)
	void upload(string s) ;
	void checknewspeed() ;
} ;

USAdrs::USAdrs() // USAdrs 클래스 생성자
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		news[i] = "0" ;
	}

	scount = 0 ;
}

void USAdrs::howmanyadrs() // 현재 주소 개수 몇개 있는지 출력
{
	ucount = count ;

	cout << "The number of address : " << ucount << endl ;
}

void USAdrs::upload(string s)
{
	if( scount == 10 )
	{
		cout << "\nSorry, Newspeed is full" << endl ;
		cout << "First, please check the past Newspeed\n" << endl ;
	}else
	{
		news[scount] = s ;

		cout << "Upload successfully in Newspeed :)\n" << endl ;

		scount++ ;
	}
}

void USAdrs::checknewspeed()
{
	cout << "Show all the Newspeed ;)" << endl ;

	for( int i = 0 ; i < scount ; i++ )
	{
		cout << endl << i+1 << "th Newspeed :)" << endl ;
		cout << news[i] << endl ;
		news[i] = "0" ;
	}

	scount = 0 ;
}

#endif