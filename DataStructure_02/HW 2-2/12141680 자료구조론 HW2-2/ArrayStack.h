#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H // ��� ���� ���� �� �ݵ�� ����

#include "RuntimeException.h"
#include "StackEmpty.h"
#include "StackFull.h" // ���� Ŭ���� ��� ���ϵ��� include

template <typename E>
class ArrayStack // ArrayStack Ŭ���� ����
{
	enum{ DEF_CAPACITY = 100 } ; // default ����

private :
	E* S ;
	int capacity ;
	int t ;

public :
	ArrayStack(int cap = DEF_CAPACITY) ; // default ������
	ArrayStack(const ArrayStack &a) ; // ���� ������
	~ArrayStack() ; // �Ҹ���
	int size() const ; // ���ÿ� ����� ���ҵ��� ����
	bool empty() const ; // ������ ������� �Ǵ�
	const E& top() const throw(StackEmpty) ; // ���� ���� ���� top �κ��� ���� ��ȯ
	void push(const E& e) throw(StackFull) ; // �ֻ��� ���� ���� ����
	void pop() throw(StackEmpty) ; // �ֻ��� ���� ���� ����
	int PIS(const E& e) const ; // ���ó��� �켱����
	int PIE(const E& e) const ; // ���ĳ��� �켱����
	void postfix(E* exp, int n) ;
} ;

template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1) // default ������
{
}

template <typename E>
ArrayStack<E>::ArrayStack(const ArrayStack &a) // ���� ������
{
	S = a.S ;
	capacity = a.capacity ;
	t = a.t ;
}

template <typename E>
ArrayStack<E>::~ArrayStack() // �Ҹ���
{

}

template <typename E>
int ArrayStack<E>::size() const // ���ÿ� ����� ���ҵ��� ����
{
	return (t + 1) ; // ex) ���ҵ� 0 ~ 6���� ����Ǿ� ������ ������ 7�� (6+1)
}

template <typename E>
bool ArrayStack<E>::empty() const // ������ ������� �Ǵ�
{
	return (t < 0) ; // 0���� �۴ٸ� ����ٰ� �Ǵ�
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) // ���� ���� ���� top �κ��� ���� ��ȯ
{
	if( empty() ) // ������ ����ٸ�
	{
		throw StackEmpty("Top of empty stack") ; // ���� Ŭ���� ����(�� ���� ���� ���)
	}
	
	return S[t] ; // ���� �ʾҴٸ� ���� �ֻ��� ���� ��ȯ
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) // �ֻ��� ���� ���� ����
{
	if( size() == capacity ) // ������ �� á�ٸ�
	{
		throw StackFull("Push to full stack") ; // ���� Ŭ���� ����(�� ���� ���� ���)
	}
	
	S[++t] = e ; // size ���� ��Ű��, �װ��� ���Ҹ� ����
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) // �ֻ��� ���� ���� ����
{
	if( empty() ) // ������ ����ٸ�
	{
		throw StackEmpty("Pop from empty stack") ; // ���� Ŭ���� ����(�� ���� ���� ���)
	}
	
	--t ; // ���� �ʾҴٸ� size �ϳ� ����
}

template <typename E>
int ArrayStack<E>::PIS(const E& e) const // ���ó��� �켱������ ����
{
	if( e == "!" )
	{
		return 6 ;
	}else if( e == "&&" || e == "||" || e == ">" || e == "<" )
	{
		return 5 ;
	}else if( e == "^" )
	{
		return 4 ;
	}else if( e == "*" || e == "/" )
	{
		return 3 ;
	}else if( e == "+" || e == "-" )
	{
		return 2 ;
	}else if( e == "(" )
	{
		return 1 ;
	}else
	{
		return -1 ;
	}
}

template <typename E>
int ArrayStack<E>::PIE(const E& e) const // ���ĳ��� �켱����
{
	if( e == "!" )
	{
		return 6 ;
	}else if( e == "&&" || e == "||" || e == ">" || e == "<" )
	{
		return 5 ;
	}else if( e == "^" )
	{
		return 4 ;
	}else if( e == "*" || e == "/" )
	{
		return 3 ;
	}else if( e == "+" || e == "-" )
	{
		return 2 ;
	}else if( e == "(" )
	{
		return 7 ;
	}else
	{
		return -1 ;
	}
}

template <typename E>
void ArrayStack<E>::postfix(E* exp, int n) // ���� ǥ��� -> ���� ǥ���
{
	int tof = 0 ; // ���� ���� ���ڴ� ��ȣ�ΰ� ? (�´ٸ� 1, �ƴϸ� 0)
	int eof = 0 ; // �� �տ� ���ڰ� ��ȣ�ΰ� ? (! �����ϰ�� ��� ������ ó��) (�´ٸ� 1, �ƴϸ� 0)
	int eo = 0 ; // eof�� temp ���� 
	int fof = 0 ; // �����ؼ� ��ȣ�� ���Դ°� ? (�´ٸ� 1, �ƴϸ� 0)

	string ot[10] = {"&&", "||", ">", "<", "^", "*", "/", "+", "-", "!"} ; // ������
	
	string token ; // ���� ����
	string ltoken ; // ���� ����

	ArrayStack<E> a ; // ����

	a.push("~") ; // ���� �� �Ʒ����� ~ ���� ����

	for( int i = 0 ; i < n ; i++ )
	{
		token = exp[i] ; // �޾ƿ� �迭�� ���� ���� -> token

		if( i == 0 ) // �� ���� ���� ���
		{
			for( int j = 0 ; j < 10 ; j++ )
			{
				if( token == "!" ) // �� ���� ���ڰ� !�� ���� ������ �ƴ� �� ������ ���
				{
					tof = 1 ; // tof = 1 (���� ���ڰ� ��ȣ, ! ���� ��ȣ)
					break ;
				}

				if( token == ot[j] ) // !�� �ƴϰ� �ٸ� �����ڶ��
				{
					eof = 1 ; // eof = 1 (�� ���� ���ڴ� ��ȣ)
					eo = eof ; // temp ������ eo�� ����
					break ;
				}
			}
		}else // ù ��° �ڸ� ����, ������ ���ڰ� ��ȣ����
		{
			for( int j = 0 ; j < 10 ; j++ )
			{
				if( token == ot[j] ) // ���� ���ڰ� ��ȣ���
				{
					tof = 1 ; // tof = 1 (���� ���ڰ� ��ȣ)
					break ;
				}
			}

			if( tof == 1 ) // ���� ���ڰ� ��ȣ���
			{
				ltoken = exp[i-1] ; // �� ���� ���ڴ�

				for( int j = 0 ; j < 10 ; j++ )
				{
					if( ltoken == ot[j] ) // ���� ��ȣ���
					{
						fof = 1 ; // fof = 1 (�� �� �������� ���ڰ� ��ȣ)
						break ;
					}
				}
			}
		}
				
		if( token == "(" ) // ���� ���ڰ� open ��ȣ���
		{
			if( i >= 1 ) // �ι�° ���ں��� ����° ���ڰ� ������
			{
				if( exp[i-1] == "!" ) // " ! ( " <- �̷� ������� ��ȣ�� ������ ���
				{
					fof = 0 ; // �װ��� ���� ��ȣ�� �� ���� ������ �ƴ�
				}
			}

			a.push(token) ; // ���ÿ� (�� ����
		}else if( token == ")") // ���� ���ڰ� close ��ȣ���
		{
			while( a.top() != "(" ) // (�� ���� �� ����
			{
				cout << a.top() << " " ; // ���� �ֻ��� ���Ҹ� ��� ���
				a.pop() ; // ���� �ֻ��� ���� ����
			}

			a.pop() ; // (�� ����
		}else if( eo == 1 || tof == 1 ) // ���� ù ��° ����, ���� ���ڰ� ��ȣ���
		{
			eo = 0 ; // �ʱ�ȭ (eof�� ������ �ڱ� ���� ����, ���߿� �� ���� �̿�)
			tof = 0 ; // tof �ʱ�ȭ

			while( PIS(a.top()) >= PIE(token) ) // �켱���� ��, ���ó��� �켱������ ���ĳ��� �켱�������� ũ�ٸ�
			{
				cout << a.top() << " " ; // �� ���ó��� ���Ұ� ���
				a.pop() ; // �� ���Ҵ� ���ÿ��� ����
			}

			a.push(token) ; // �׸��� ���� ���ڸ� ����

		}else if( token == "@" ) // ���ڰ� @��� (������ ���ڶ��)
		{
			if( fof == 1 ) // ������ ��ȣ�� �ִ��� ? ex) A *- B + C // ����
			{
				cout << "\nError Equation" ; // ���� ���
				break ;
			}

			while( a.top() != "~" ) 
			{
				if( a.top() == "!" ) // ����ǥ�� �����Ѵٸ� ���
				{
					cout << a.top() << " " ;
					a.pop() ;
				}else if( eof == 1 && a.top() != "!" ) // �� ���� ���ڰ� !�� �ƴ� ��ȣ���� ?
				{
					cout << a.top() << " " ; // ex) -A + B - C + D / *A + B - C + D // ����
					cout << "\nError Equation" ; // ���� ���
					break ;
				}else
				{
					cout << a.top() << " " ;
					a.pop() ;
				}
			}
		}else // ��ȣ�� �ƴ� ���ڶ��
		{
			cout << token << " " ; // �ٷ� ���
		}
	}
}

#endif