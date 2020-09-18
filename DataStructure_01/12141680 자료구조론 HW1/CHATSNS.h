#ifndef CHATSNS_H
#define CHATSNS_H

// ���� CHATSNS.h ������ �������� �ʴ´ٸ� ���� (��� ���� �ۼ� �� �ʼ�)
// 12141680 CSAdrs

#include <iostream>
#include <string>

using namespace std ;

#include "SNSADRS.h"

class CSAdrs : public SNSAdrs // Ŭ������ ��� ���� (�θ� Ŭ���� : SNSAdrs, �ڽ� Ŭ���� : CSAdrs)
{
private :
	string text ;
	int ccount ; // CSAdrs Ŭ������ �ּ� ����

public :
	CSAdrs() {} ; // ������
	~CSAdrs() {} ; // �Ҹ���
	void howmanyadrs() ; // ���� �ּ� ���� � �ִ����� ��� (�θ� Ŭ�������� virtual function���� ����)
	void sendmessage(int i) ; // overloading �Լ�(�޼ҵ�), ���� ; int ��
	void sendmessage(string s) ; // overloading �Լ�(�޼ҵ�), ���� ; string ��
} ;

void CSAdrs::howmanyadrs() // ���� �ּ� ���� � �ִ��� ���
{
	ccount = count ;

	cout << "The number of address : " << ccount << endl ;
}

void CSAdrs::sendmessage(int i) // ������ int������ �޾ƿ����ٸ� �� �Լ��� ����
{
	cout << "To. 010" << i << endl ;

	cout << "Enter a message : " << endl ;

	cin >> text ;

	cout << "message is sent successfully" << endl ;
}

void CSAdrs::sendmessage(string s) // ������ string������ �޾ƿ����ٸ� �� �Լ��� ����
{
	cout << "To. " << s << endl ;

	cout << "Enter a message : " << endl ;

	cin >> text ;

	cout << "message is sent successfully" << endl ;
}

#endif