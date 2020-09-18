#ifndef STACKFULL_H
#define STACKFULL_H // ��� ���� ���� �� �ݵ�� ����

#include <string>
#include <string.h>

#include "RuntimeException.h"

class StackFull : public RuntimeException // StackFull Ŭ���� ���� (���� Ŭ����) // RuntimeException Ŭ������ ��� ����
{
public :
	StackFull(const string &err) : RuntimeException(err) // ������ // �޾ƿ� ������ StackFull�� ����
	{
		cout << getMessage() << endl ; // �޾ƿ� ������ ���
	}
} ;

#endif