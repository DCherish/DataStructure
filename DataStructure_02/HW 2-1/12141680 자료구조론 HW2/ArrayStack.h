#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H // 헤더 파일 생성 시 반드시 선언

#include "RuntimeException.h"
#include "StackEmpty.h"
#include "StackFull.h" // 예외 클래스 헤더 파일들을 include

template <typename E>
class ArrayStack // ArrayStack 클래스 선언
{
	enum{ DEF_CAPACITY = 100 } ; // default 선언

private :
	E* S ;
	int capacity ;
	int t ;

public :
	ArrayStack(int cap = DEF_CAPACITY) ; // default 생성자
	ArrayStack(const ArrayStack &a) ; // 복사 생성자
	~ArrayStack() ; // 소멸자
	int size() const ; // 스택에 저장된 원소들의 갯수
	bool empty() const ; // 스택이 비었는지 판단
	const E& top() const throw(StackEmpty) ; // 스택 내의 가장 top 부분의 원소 반환
	void push(const E& e) throw(StackFull) ; // 최상위 스택 원소 저장
	void pop() throw(StackEmpty) ; // 최상위 스택 원소 삭제
} ;

template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1) // default 생성자
{
}

template <typename E>
ArrayStack<E>::ArrayStack(const ArrayStack &a) // 복사 생성자
{
	S = a.S ;
	capacity = a.capacity ;
	t = a.t ;
}

template <typename E>
ArrayStack<E>::~ArrayStack() // 소멸자
{

}

template <typename E>
int ArrayStack<E>::size() const // 스택에 저장된 원소들의 갯수
{
	return (t + 1) ; // ex) 원소들 0 ~ 6번방 저장되어 있으면 갯수는 7개 (6+1)
}

template <typename E>
bool ArrayStack<E>::empty() const // 스택이 비었는지 판단
{
	return (t < 0) ; // 0보다 작다면 비었다고 판단
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) // 스택 내의 가장 top 부분의 원소 반환
{
	if( empty() ) // 스택이 비었다면
	{
		throw StackEmpty("Top of empty stack") ; // 예외 클래스 실행(써 놓은 문구 출력)
	}
	
	return S[t] ; // 비지 않았다면 가장 최상위 원소 반환
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) // 최상위 스택 원소 저장
{
	if( size() == capacity ) // 스택이 꽉 찼다면
	{
		throw StackFull("Push to full stack") ; // 예외 클래스 실행(써 놓은 문구 출력)
	}
	
	S[++t] = e ; // size 증가 시키며, 그곳에 원소를 저장
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) // 최상위 스택 원소 삭제
{
	if( empty() ) // 스택이 비었다면
	{
		throw StackEmpty("Pop from empty stack") ; // 예외 클래스 실행(써 놓은 문구 출력)
	}
	
	--t ; // 비지 않았다면 size 하나 감소
}

#endif