#include <iostream>
#include <stack>
#include <string>
#include <string.h>

#include "ArrayStack.h"
#include "RuntimeException.h"
#include "StackEmpty.h"
#include "StackFull.h" // 헤더 파일들을 include

using namespace std ;

int main()
{
	cout << "12141680 ArrayStack" << endl << endl ;

	ArrayStack<int> A ; // int형 A객체 생성 // 최대 int 100개 입력 가능 (default)
	A.push(7) ; // 7을 스택으로 집어 넣음 // 최상위 원소 : 7
	A.push(13) ; // 13을 스택으로 집어 넣음 // 최상위 원소 : 7 -> 13
	cout << A.top() << endl ; // 최상위 원소 반환 // // 최상위 원소 : 13 출력
	A.pop() ; // 최상위 원소 삭제 // 최상위 원소 : 13 -> 7
	A.push(9) ; // 9를 스택으로 집어 넣음 // 최상위 원소 : 7 -> 9
	cout << A.top() << endl ; // 최상위 원소 반환 // // 최상위 원소 : 9 출력
	cout << A.top() << endl ; // 최상위 원소 반환 // // 최상위 원소 : 9 출력
	A.pop() ; // 최상위 원소 삭제 // 최상위 원소 : 9 -> 7

	ArrayStack<string> B(10) ; // string형 B객체 생성 // 최대 string 10개 입력 가능
	B.push("Bob") ; // Bob 을 스택으로 집어 넣음 // 최상위 원소 : Bob
	B.push("Alice") ; // Alice 를 스택으로 집어 넣음 // 최상위 원소 : Bob -> Alice
	cout << B.top() << endl ; // 최상위 원소 반환 // // 최상위 원소 : Alice 출력
	B.pop() ; // 최상위 원소 삭제 // 최상위 원소 : Alice -> Bob
	B.push("Eve") ; // Eve 를 스택으로 집어 넣음 // 최상위 원소 : Bob -> Eve

	return 0 ;
}