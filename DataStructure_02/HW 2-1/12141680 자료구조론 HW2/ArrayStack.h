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

#endif