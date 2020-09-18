#ifndef PHOTOSNS_H
#define PHOTOSNS_H

// ���� PHOTOSNS.h ������ �������� �ʴ´ٸ� ���� (��� ���� �ۼ� �� �ʼ�)
// 12141680 PSAdrs

#include <iostream>

using namespace std ;

#include "SNSADRS.h"
#include "UPLOADSNS.h"

class PSAdrs : public USAdrs // Ŭ������ ��� ���� (�θ� Ŭ���� : USAdrs, �ڽ� Ŭ���� : PSAdrs)
{
public :
	PSAdrs() {} ; // ������
	~PSAdrs() {} ; // �Ҹ���

	template <typename T> // template
	void Hashtag(T a) ;
} ;

template <typename T>
void PSAdrs::Hashtag(T a) // �Է¹��� ���� ���� ���� �ٸ� ������ ���
{
	if( sizeof(a) == 4 ) // ���� int���̶�� sizeof(a) = 4byte�� �Ǿ� �� ������ ���
	{
		cout << "#" << a << "��" << endl ;
	}else // 4byte�� �ƴ϶�� �� �������� ���
	{
		cout << "#" << a << "��" << endl ;
	}
}

#endif