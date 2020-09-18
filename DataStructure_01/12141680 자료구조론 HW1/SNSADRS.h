#ifndef SNSADRS_H
#define SNSADRS_H

// 만약 SNSADRS.h 파일이 존재하지 않는다면 선언 (헤더 파일 작성 시 필수)
// 12141680 SNSAdrs

#include <iostream>

using namespace std ;

class SNSAdrs
{
private :
	char *address[10] ; // 받아온 주소들을 저장하는 배열
	int index ;

protected :
	int count ; // 각각 현재 저장된 주소 개수 = count

public :
	SNSAdrs() ; // 생성자
	virtual ~SNSAdrs() {} ; // virtual destructor
	void insadrs(char *a) ; // 주소를 입력받는 기능의 함수
	void deladrs(char *a) ; // 입력받은 주소를 삭제하는 기능의 함수
	int findadrs(char *a) ; // 삭제할 때 주소가 존재하는 지 찾아보는 함수
	void searchadrs(char *a) ; // 주소를 검색하는 기능의 함수
	virtual void howmanyadrs() = 0 ; // virtual function (pure virtual function)
} ;

SNSAdrs::SNSAdrs() // SNSAdrs 클래스 생성자
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		address[i] = "0" ;
	}
	
	count = 0 ;
	index = 0 ;
} // 생성자 선언 시 변수들을 초기화

void SNSAdrs::insadrs(char *a)
{
	if( count > 10 )
	{
		cout << "can not insert anymore" << endl ;
		return ;
	} // 주소가 많이 받아지지 못하도록 받는 개수를 제한

	for( int i = 0 ; i <= count ; i++ ) // 개수를 초과하지 않았다면
	{
		if( address[i] != "0" )
		{
		}else
		{
			address[i] = a ; // 받아온 주소를 배열에 저장
			count++ ; // 주소 개수를 증가 
			break ;
		}
	}
}

void SNSAdrs::deladrs(char *a)
{
	if( count == 0 ) // 현재 주소 개수가 한개도 없다면
	{
		cout << "No address" << endl ; // 주소가 한개도 없다고 출력
		return ;
	}else
	{
		if( findadrs(a) == 1 ) // 만약 삭제하고자 하는 주소를 찾았다면
		{
			cout << "Delete " << a << " Successfully" << endl ; // 정상적으로 삭제 했다는 것을 출력
			address[index] = "0" ; // 삭제
			count-- ; // 주소 개수를 감소
		}
	}
}

int SNSAdrs::findadrs(char *a)
{
	int z = 0 ;

	for( int i = 0 ; i < count ; i++ )
	{
		if( address[i] == a ) // 받아온 주소와 저장되어 있는 주소들을 비교해서 존재한다면
		{
			z = 1 ; // 있다는 것을 알려주는 역할
			index = count ; // 배열의 몇 번째에 존재하는지 index로 표시
			break ;
		}
	}

	if( z == 0 ) // 만약 삭제하고자 하는 주소가 없다면
	{
		cout << "There is No " << a << " that you want to delete" << endl ; // 주소가 없다고 출력
	}

	return z ;
}

void SNSAdrs::searchadrs(char *a) // findadrs와 구조가 거의 동일
{
	int z = 0 ;

	for( int i = 0 ; i < count ; i++ )
	{
		if( address[i] == a )
		{
			z = 1 ;
			index = count ;
			break ;
		}
	}

	if( z == 0 ) // 찾고자 하는 주소가 없다면
	{
		cout << "There is No " << a << " that you want to search" << endl ; // 없다고 출력
	}else // 찾고자 하는 주소가 존재한다면
	{
		cout << "There is " << a << " that you want to search" << endl ; // 있다고 출력
	}
}

#endif