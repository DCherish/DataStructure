#include <iostream>
#include <stack>
#include <string>
#include <string.h>

#include "ArrayStack.h"
#include "RuntimeException.h"
#include "StackEmpty.h"
#include "StackFull.h" // ��� ���ϵ��� include

using namespace std ;

int main()
{
	cout << "12141680 ArrayStack" << endl << endl ;

	ArrayStack<int> A ; // int�� A��ü ���� // �ִ� int 100�� �Է� ���� (default)
	A.push(7) ; // 7�� �������� ���� ���� // �ֻ��� ���� : 7
	A.push(13) ; // 13�� �������� ���� ���� // �ֻ��� ���� : 7 -> 13
	cout << A.top() << endl ; // �ֻ��� ���� ��ȯ // // �ֻ��� ���� : 13 ���
	A.pop() ; // �ֻ��� ���� ���� // �ֻ��� ���� : 13 -> 7
	A.push(9) ; // 9�� �������� ���� ���� // �ֻ��� ���� : 7 -> 9
	cout << A.top() << endl ; // �ֻ��� ���� ��ȯ // // �ֻ��� ���� : 9 ���
	cout << A.top() << endl ; // �ֻ��� ���� ��ȯ // // �ֻ��� ���� : 9 ���
	A.pop() ; // �ֻ��� ���� ���� // �ֻ��� ���� : 9 -> 7

	ArrayStack<string> B(10) ; // string�� B��ü ���� // �ִ� string 10�� �Է� ����
	B.push("Bob") ; // Bob �� �������� ���� ���� // �ֻ��� ���� : Bob
	B.push("Alice") ; // Alice �� �������� ���� ���� // �ֻ��� ���� : Bob -> Alice
	cout << B.top() << endl ; // �ֻ��� ���� ��ȯ // // �ֻ��� ���� : Alice ���
	B.pop() ; // �ֻ��� ���� ���� // �ֻ��� ���� : Alice -> Bob
	B.push("Eve") ; // Eve �� �������� ���� ���� // �ֻ��� ���� : Bob -> Eve

	return 0 ;
}