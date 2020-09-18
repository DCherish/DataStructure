#include <iostream>

using namespace std ;

#include "SNSADRS.h"
#include "CHATSNS.h"
#include "UPLOADSNS.h"
#include "PHOTOSNS.h"

int main(void)
{
	SNSAdrs *sa[2] ; // SNSAdrs 클래스 선언 (Polymorphism)
	sa[0] = new CSAdrs ; // SNSAdrs을 상속받은 CSAdrs 클래스 선언 (Polymorphism)
	sa[1] = new USAdrs ; // SNSAdrs을 상속받은 USAdrs 클래스 선언 (Polymorphism)

	sa[0]->insadrs("Kakaotalk") ; // SNSAdrs을 상속받은 자식클래스 CSAdrs에 주소를 추가
	sa[0]->insadrs("Line") ;
	sa[0]->insadrs("Nateon") ;
	sa[0]->insadrs("Discord") ; 

	// CSAdrs에 주소 4개가 추가됨

	sa[1]->insadrs("Facebook") ; // SNSAdrs을 상속받은 자식클래스 USAdrs에 주소를 추가
	sa[1]->insadrs("KaKaostory") ;
	sa[1]->insadrs("Twitter") ;

	// USAdrs에 주소 3개가 추가됨

	cout << "12141680 Polymorphism" << endl << endl ;

	for( int i = 0 ; i < 2 ; i++ )  // Polymorphism, 동적 바인딩
	{
		sa[i]->howmanyadrs() ; // 상속받은 각 클래스의 현재 주소 개수를 출력
	}

	cout << endl ;

	sa[0]->deladrs("Discord") ; // CSAdrs의 주소를 삭제
	sa[1]->deladrs("AfreecaTV") ; // USAdrs의 주소를 삭제

	// 있으면 삭제, 없으면 없다고 출력

	cout << endl ;

	for( int i = 0 ; i < 2 ; i++ )
	{
		sa[i]->howmanyadrs() ; // 상속받은 각 클래스의 현재 주소 개수를 출력
	}

	cout << endl ;

	sa[0]->searchadrs("Google") ; // CSAdrs에서 주소를 검색
	sa[1]->searchadrs("Facebook") ; // USAdrs에서 주소를 검색

	// 있으면 검색, 없으면 없다고 출력

	return 0 ;
}