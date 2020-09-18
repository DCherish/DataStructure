#include <iostream>
#include <string>

using namespace std ;

#include "SNSADRS.h"
#include "CHATSNS.h"
#include "UPLOADSNS.h"
#include "PHOTOSNS.h"

int main(void)
{
	int e, f, g, h ;
	string s ;

	CSAdrs *c = new CSAdrs ; // CSAdrs 클래스 생성
	USAdrs *u = new USAdrs ; // USAdrs 클래스 생성
	PSAdrs *p = new PSAdrs ; // PSAdrs 클래스 생성
	
	cout << "12141680 Template" << endl << endl ;

	cout << "Enter PhoneNumber (except 010) : " ;
	cin >> e ;

	c->sendmessage(e) ; // 입력받은 변수 int형 (같은 함수이름) -> overloading
	cout << endl ;

	cout << "Enter Name : " ;
	cin >> s ;

	c->sendmessage(s) ; // 입력받은 변수 string형 (같은 함수이름) -> overloading
	cout << endl ;

	for(;;)
	{
		cout << "Welcome X) Newspeed ;P" << endl ;

		cout << "1. Upload newspeed  2. Check newspeed  3. Hashtag  4. Quit" << endl ;

		cout << "Enter : " ;

		cin >> f ;

		cout << endl ;

		if( f == 1 )
		{
			cout << "Enter a text :" << endl ;

			cin >> s ;

			u->upload(s) ;
		}else if( f == 2 )
		{
			u->checknewspeed() ;
			cout << endl ;
		}else if( f == 3 )
		{
			cout << "Hi, Hashtag 8)" << endl ;
			cout << "1. Number  2. Text" << endl ;
			cout << "Enter : " ;
			cin >> g ;

			if( g == 1 ) // template이 잘 실행되나 확인을 위하여 응용 설계
			{
				cout << "Enter Number : " ;
				cin >> h ;
				p->Hashtag(h) ; // 입력받은 변수 int형 (template -> int 인식)
			}else
			{
				cout << "Enter Text : " ;
				cin >> s ;
				p->Hashtag(s) ; // 입력받은 변수 string형 (template -> string 인식)
			}

			cout << endl ;
		}else if( f == 4 )
		{
			cout << "Enter Text in PhotoSNS : " ;
			cin >> s ;

			p->upload(s) ;

			cout << "Hello XD. This is PhotoSNS Newspeed" << endl ;

			p->checknewspeed() ;
			
			cout << endl ;

			cout << "bye :)" << endl ;

			break ;
		}else
		{
			cout << "Wrong Number X(\n" << endl ;
		}
	}

	return 0 ;
}