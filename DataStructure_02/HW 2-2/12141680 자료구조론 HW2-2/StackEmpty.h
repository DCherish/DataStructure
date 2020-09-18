#ifndef STACKEMPTY_H
#define STACKEMPTY_H // ��� ���� ���� �� �ݵ�� ����

#include <string>
#include <string.h>

#include "RuntimeException.h"

class StackEmpty : public RuntimeException // StackEmpty Ŭ���� ���� (���� Ŭ����) // RuntimeException Ŭ������ ��� ����
{
public :
	StackEmpty(const string& err) : RuntimeException(err) // ������ // �޾ƿ� ������ StackEmpty�� ����
	{
		cout << getMessage() << endl ; // �޾ƿ� ������ ���
	}
} ;

#endif