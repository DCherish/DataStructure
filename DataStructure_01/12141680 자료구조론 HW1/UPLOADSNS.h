#ifndef UPLOADSNS_H
#define UPLOADSNS_H

// ���� UPLOADSNS.h ������ �������� �ʴ´ٸ� ���� (��� ���� �ۼ� �� �ʼ�)
// 12141680 USAdrs

#include <iostream>
#include <string>

using namespace std ;

#include "SNSADRS.h"

class USAdrs : public SNSAdrs // Ŭ������ ��� ���� (�θ� Ŭ���� : SNSAdrs, �ڽ� Ŭ���� : USAdrs)
{
private :
	string news[10] ;
	int ucount ;
	int scount ;

public :
	USAdrs() ; // ������
	virtual ~USAdrs() {} ; // virtual destructor
	void howmanyadrs() ; // ���� �ּ� ���� � �ִ����� ��� (�θ� Ŭ�������� virtual function���� ����)
	void upload(string s) ;
	void checknewspeed() ;
} ;

USAdrs::USAdrs() // USAdrs Ŭ���� ������
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		news[i] = "0" ;
	}

	scount = 0 ;
}

void USAdrs::howmanyadrs() // ���� �ּ� ���� � �ִ��� ���
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