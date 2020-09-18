#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H // ��� ���� ���� �� �ݵ�� ����

#include <iostream>
#include <string>
#include <string.h>

#include "ArrayStack.h"

using namespace std ;

class RuntimeException // RunTimeException Ŭ���� ���� (���� Ŭ����)
{
private :
	string errorMsg ;

public :
	RuntimeException(const string &err) // ������
	{
		errorMsg = err ; // �Էµ� ������ �޾ƿ� ����
	}

	string getMessage() const
	{
		return errorMsg ; // �޾ƿ��� ������ ���
	}
} ;

#endif