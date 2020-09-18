#include <iostream>

using namespace std ;

#include "SNSADRS.h"
#include "CHATSNS.h"
#include "UPLOADSNS.h"
#include "PHOTOSNS.h"

int main(void)
{
	SNSAdrs *sa[2] ; // SNSAdrs Ŭ���� ���� (Polymorphism)
	sa[0] = new CSAdrs ; // SNSAdrs�� ��ӹ��� CSAdrs Ŭ���� ���� (Polymorphism)
	sa[1] = new USAdrs ; // SNSAdrs�� ��ӹ��� USAdrs Ŭ���� ���� (Polymorphism)

	sa[0]->insadrs("Kakaotalk") ; // SNSAdrs�� ��ӹ��� �ڽ�Ŭ���� CSAdrs�� �ּҸ� �߰�
	sa[0]->insadrs("Line") ;
	sa[0]->insadrs("Nateon") ;
	sa[0]->insadrs("Discord") ; 

	// CSAdrs�� �ּ� 4���� �߰���

	sa[1]->insadrs("Facebook") ; // SNSAdrs�� ��ӹ��� �ڽ�Ŭ���� USAdrs�� �ּҸ� �߰�
	sa[1]->insadrs("KaKaostory") ;
	sa[1]->insadrs("Twitter") ;

	// USAdrs�� �ּ� 3���� �߰���

	cout << "12141680 Polymorphism" << endl << endl ;

	for( int i = 0 ; i < 2 ; i++ )  // Polymorphism, ���� ���ε�
	{
		sa[i]->howmanyadrs() ; // ��ӹ��� �� Ŭ������ ���� �ּ� ������ ���
	}

	cout << endl ;

	sa[0]->deladrs("Discord") ; // CSAdrs�� �ּҸ� ����
	sa[1]->deladrs("AfreecaTV") ; // USAdrs�� �ּҸ� ����

	// ������ ����, ������ ���ٰ� ���

	cout << endl ;

	for( int i = 0 ; i < 2 ; i++ )
	{
		sa[i]->howmanyadrs() ; // ��ӹ��� �� Ŭ������ ���� �ּ� ������ ���
	}

	cout << endl ;

	sa[0]->searchadrs("Google") ; // CSAdrs���� �ּҸ� �˻�
	sa[1]->searchadrs("Facebook") ; // USAdrs���� �ּҸ� �˻�

	// ������ �˻�, ������ ���ٰ� ���

	return 0 ;
}