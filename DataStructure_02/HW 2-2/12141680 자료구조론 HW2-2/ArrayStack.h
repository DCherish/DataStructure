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
	int PIS(const E& e) const ; // 스택내의 우선순위
	int PIE(const E& e) const ; // 수식내의 우선순위
	void postfix(E* exp, int n) ;
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

template <typename E>
int ArrayStack<E>::PIS(const E& e) const // 스택내의 우선순위를 설정
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
int ArrayStack<E>::PIE(const E& e) const // 수식내의 우선순위
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
void ArrayStack<E>::postfix(E* exp, int n) // 중위 표기법 -> 후위 표기법
{
	int tof = 0 ; // 현재 받은 문자는 기호인가 ? (맞다면 1, 아니면 0)
	int eof = 0 ; // 맨 앞에 문자가 기호인가 ? (! 제외하고는 모두 오류로 처리) (맞다면 1, 아니면 0)
	int eo = 0 ; // eof의 temp 역할 
	int fof = 0 ; // 연속해서 기호가 나왔는가 ? (맞다면 1, 아니면 0)

	string ot[10] = {"&&", "||", ">", "<", "^", "*", "/", "+", "-", "!"} ; // 연산자
	
	string token ; // 현재 문자
	string ltoken ; // 전의 문자

	ArrayStack<E> a ; // 생성

	a.push("~") ; // 스택 맨 아래에는 ~ 문자 삽입

	for( int i = 0 ; i < n ; i++ )
	{
		token = exp[i] ; // 받아온 배열의 현재 문자 -> token

		if( i == 0 ) // 맨 앞의 문자 고려
		{
			for( int j = 0 ; j < 10 ; j++ )
			{
				if( token == "!" ) // 맨 앞의 문자가 !일 경우는 오류가 아닐 수 있음을 고려
				{
					tof = 1 ; // tof = 1 (현재 문자가 기호, ! 역시 기호)
					break ;
				}

				if( token == ot[j] ) // !가 아니고 다른 연산자라면
				{
					eof = 1 ; // eof = 1 (맨 앞의 문자는 기호)
					eo = eof ; // temp 역할의 eo에 저장
					break ;
				}
			}
		}else // 첫 번째 자리 제외, 현재의 문자가 기호인지
		{
			for( int j = 0 ; j < 10 ; j++ )
			{
				if( token == ot[j] ) // 현재 문자가 기호라면
				{
					tof = 1 ; // tof = 1 (현재 문자가 기호)
					break ;
				}
			}

			if( tof == 1 ) // 현재 문자가 기호라면
			{
				ltoken = exp[i-1] ; // 그 전의 문자는

				for( int j = 0 ; j < 10 ; j++ )
				{
					if( ltoken == ot[j] ) // 역시 기호라면
					{
						fof = 1 ; // fof = 1 (두 개 연속으로 문자가 기호)
						break ;
					}
				}
			}
		}
				
		if( token == "(" ) // 받은 문자가 open 괄호라면
		{
			if( i >= 1 ) // 두번째 문자부터 전번째 문자가 존재함
			{
				if( exp[i-1] == "!" ) // " ! ( " <- 이런 모습으로 기호가 연속일 경우
				{
					fof = 0 ; // 그것은 연속 기호라 할 지라도 에러가 아님
				}
			}

			a.push(token) ; // 스택에 (를 삽입
		}else if( token == ")") // 받은 문자가 close 괄호라면
		{
			while( a.top() != "(" ) // (가 나올 때 까지
			{
				cout << a.top() << " " ; // 스택 최상위 원소를 모두 출력
				a.pop() ; // 스택 최상위 원소 삭제
			}

			a.pop() ; // (를 삭제
		}else if( eo == 1 || tof == 1 ) // 만약 첫 번째 문자, 현재 문자가 기호라면
		{
			eo = 0 ; // 초기화 (eof는 여전히 자기 값을 유지, 나중에 그 값을 이용)
			tof = 0 ; // tof 초기화

			while( PIS(a.top()) >= PIE(token) ) // 우선순위 비교, 스택내의 우선순위가 수식내의 우선순위보다 크다면
			{
				cout << a.top() << " " ; // 그 스택내의 원소가 출력
				a.pop() ; // 그 원소는 스택에서 삭제
			}

			a.push(token) ; // 그리고 현재 문자를 저장

		}else if( token == "@" ) // 문자가 @라면 (마지막 문자라면)
		{
			if( fof == 1 ) // 연속한 기호가 있는지 ? ex) A *- B + C // 에러
			{
				cout << "\nError Equation" ; // 에러 출력
				break ;
			}

			while( a.top() != "~" ) 
			{
				if( a.top() == "!" ) // 느낌표가 존재한다면 출력
				{
					cout << a.top() << " " ;
					a.pop() ;
				}else if( eof == 1 && a.top() != "!" ) // 맨 앞의 문자가 !가 아닌 기호인지 ?
				{
					cout << a.top() << " " ; // ex) -A + B - C + D / *A + B - C + D // 에러
					cout << "\nError Equation" ; // 에러 출력
					break ;
				}else
				{
					cout << a.top() << " " ;
					a.pop() ;
				}
			}
		}else // 기호가 아닌 문자라면
		{
			cout << token << " " ; // 바로 출력
		}
	}
}

#endif