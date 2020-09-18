#ifndef SNSADRS_H
#define SNSADRS_H

// ���� SNSADRS.h ������ �������� �ʴ´ٸ� ���� (��� ���� �ۼ� �� �ʼ�)
// 12141680 SNSAdrs

#include <iostream>

using namespace std ;

class SNSAdrs
{
private :
	char *address[10] ; // �޾ƿ� �ּҵ��� �����ϴ� �迭
	int index ;

protected :
	int count ; // ���� ���� ����� �ּ� ���� = count

public :
	SNSAdrs() ; // ������
	virtual ~SNSAdrs() {} ; // virtual destructor
	void insadrs(char *a) ; // �ּҸ� �Է¹޴� ����� �Լ�
	void deladrs(char *a) ; // �Է¹��� �ּҸ� �����ϴ� ����� �Լ�
	int findadrs(char *a) ; // ������ �� �ּҰ� �����ϴ� �� ã�ƺ��� �Լ�
	void searchadrs(char *a) ; // �ּҸ� �˻��ϴ� ����� �Լ�
	virtual void howmanyadrs() = 0 ; // virtual function (pure virtual function)
} ;

SNSAdrs::SNSAdrs() // SNSAdrs Ŭ���� ������
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		address[i] = "0" ;
	}
	
	count = 0 ;
	index = 0 ;
} // ������ ���� �� �������� �ʱ�ȭ

void SNSAdrs::insadrs(char *a)
{
	if( count > 10 )
	{
		cout << "can not insert anymore" << endl ;
		return ;
	} // �ּҰ� ���� �޾����� ���ϵ��� �޴� ������ ����

	for( int i = 0 ; i <= count ; i++ ) // ������ �ʰ����� �ʾҴٸ�
	{
		if( address[i] != "0" )
		{
		}else
		{
			address[i] = a ; // �޾ƿ� �ּҸ� �迭�� ����
			count++ ; // �ּ� ������ ���� 
			break ;
		}
	}
}

void SNSAdrs::deladrs(char *a)
{
	if( count == 0 ) // ���� �ּ� ������ �Ѱ��� ���ٸ�
	{
		cout << "No address" << endl ; // �ּҰ� �Ѱ��� ���ٰ� ���
		return ;
	}else
	{
		if( findadrs(a) == 1 ) // ���� �����ϰ��� �ϴ� �ּҸ� ã�Ҵٸ�
		{
			cout << "Delete " << a << " Successfully" << endl ; // ���������� ���� �ߴٴ� ���� ���
			address[index] = "0" ; // ����
			count-- ; // �ּ� ������ ����
		}
	}
}

int SNSAdrs::findadrs(char *a)
{
	int z = 0 ;

	for( int i = 0 ; i < count ; i++ )
	{
		if( address[i] == a ) // �޾ƿ� �ּҿ� ����Ǿ� �ִ� �ּҵ��� ���ؼ� �����Ѵٸ�
		{
			z = 1 ; // �ִٴ� ���� �˷��ִ� ����
			index = count ; // �迭�� �� ��°�� �����ϴ��� index�� ǥ��
			break ;
		}
	}

	if( z == 0 ) // ���� �����ϰ��� �ϴ� �ּҰ� ���ٸ�
	{
		cout << "There is No " << a << " that you want to delete" << endl ; // �ּҰ� ���ٰ� ���
	}

	return z ;
}

void SNSAdrs::searchadrs(char *a) // findadrs�� ������ ���� ����
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

	if( z == 0 ) // ã���� �ϴ� �ּҰ� ���ٸ�
	{
		cout << "There is No " << a << " that you want to search" << endl ; // ���ٰ� ���
	}else // ã���� �ϴ� �ּҰ� �����Ѵٸ�
	{
		cout << "There is " << a << " that you want to search" << endl ; // �ִٰ� ���
	}
}

#endif