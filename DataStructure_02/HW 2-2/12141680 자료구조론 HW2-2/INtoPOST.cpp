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
	cout << "12141680 Infix to Postfix" << endl << endl ;

	ArrayStack<string> A ;

	const int z1 = 6 ;
	string zz1[z1] = {"A", "*", "B", "*", "C", "@"} ;
	cout << "1) : " ;
	A.postfix(zz1, z1) ;
	cout << endl << endl ;

	const int z2 = 18 ;
	string zz2[z2] = {"(", "(", "A", "+", "(", "B", "*", "C", ")", ")", "-", "(", "D", "/", "E", ")", ")", "@"} ;
	cout << "2) : " ;
	A.postfix(zz2, z2) ;
	cout << endl << endl ;

	const int z3 = 9 ;
	string zz3[z3] = {"-", "A", "+", "B", "-", "C", "+", "D" , "@"} ;
	cout << "3) : " ;
	A.postfix(zz3, z3) ;
	cout << endl << endl ;

	const int z4 = 7 ;
	string zz4[z4] = {"A", "*", "-", "B", "+", "C", "@"} ;
	cout << "4) : " ;
	A.postfix(zz4, z4) ;
	cout << endl << endl ;

	const int z5 = 20 ;
	string zz5[z5] = {"(", "A", "+", "B", ")", "*", "D", "+", "E", "/", "(", "F", "+", "A", "*", "D", ")", "+", "C", "@"} ;
	cout << "5) : " ;
	A.postfix(zz5, z5) ;
	cout << endl << endl ;

	const int z6 = 13 ;
	string zz6[z6] = {"A", "&&", "B", "||", "C", "||", "!", "(", "E", ">", "F", ")", "@"} ;
	cout << "6) : " ;
	A.postfix(zz6, z6) ;
	cout << endl << endl ;

	const int z7 = 26 ;
	string zz7[z7] = {"!", "(", "A", "&&", "!", "(", "(", "B", "<", "C", ")", "||", "(", "C", ">", "D", ")", ")", ")", "||", "(", "C", "<", "E", ")", "@"} ;
	cout << "7) : " ;
	A.postfix(zz7, z7) ;
	cout << endl << endl ;

	const int z8 = 10 ;
	string zz8[z8] = {"(", "A", "+", "B", ")", ")", "A", "+", "B", "@"} ; // 매칭 되지 않는 ) 문자 삽입으로 StackEmpty 예외 유도
	cout << "Bonus) : " ;
	A.postfix(zz8, z8) ;
	cout << endl << endl ;

	return 0 ;
}