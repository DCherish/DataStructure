#include <iostream>
#include <string.h>

using namespace std ;

typedef char Elem ; // Elem들은 char형
class DNode
{
	Elem elem ;
	DNode *prev ;
	DNode *next ;
	friend class DLinkedList ;
} ;

class DLinkedList
{
public :
	DLinkedList() ; // 생성자
	~DLinkedList() ; // 소멸자
	bool empty() const ; // List가 empty한지 ?
	const Elem& front() const ; // 맨 앞의 원소 (header -> next)
	const Elem& back() const ; // 맨 뒤의 원소 (trailer -> prev)
	void addFront(const Elem& e) ; // 맨 앞에 원소를 추가 (header -> next)
	void addBack(const Elem& e) ; // 맨 뒤에 원소를 추가 (trailer -> prev)
	void removeFront() ; // 맨 앞쪽 원소를 제거 (header -> next)
	void removeBack() ; // 맨 뒤쪽 원소를 제거 (trailer -> prev)

	friend class DLLStack ; // Doubly Linked List를 응용한 Stack

private :
	DNode *header ;
	DNode *trailer ;

protected :
	void add(DNode *v, const Elem& e) ;
	void remove(DNode *v) ;
} ;

DLinkedList::DLinkedList() // header와 trailer가 생성 시에는 서로가 서로를 가르키고 있음
{
	header = new DNode ;
	trailer = new DNode ;
	header->next = trailer ;
	trailer->prev = header ;
}

DLinkedList::~DLinkedList() // 맨 앞쪽부터 모든 원소를 삭제 후, header 및 trailer 삭제
{
	while( !empty() ) removeFront() ;
	delete header ;
	delete trailer ;
}

void DLinkedList::add(DNode *v, const Elem& e) // 한 노드 기준, 그 노드 바로 앞으로 추가
{
	DNode *u = new DNode ;
	u->elem = e ;
	u->next = v ;
	u->prev = v->prev ;
	v->prev->next = u ;
	v->prev = u ;
}

void DLinkedList::addFront(const Elem& e) // 맨 앞에 원소를 추가
{
	add(header->next, e) ;
}

void DLinkedList::addBack(const Elem& e) // 맨 뒤에 원소를 추가
{
	add(trailer, e) ;
}

void DLinkedList::remove(DNode *v) // 한 노드 기준, 그 노드 앞 뒤끼리 이은 후 자신을 삭제
{
	DNode *u = v->prev ;
	DNode *w = v->next ;
	u->next = w ;
	w->prev = u ;

	delete v ;
}

void DLinkedList::removeFront() // 맨 앞의 원소를 삭제
{
	if( !empty() )
	{
		remove(header->next) ;
	}else
	{
		cout << "Can not remove. Empty" << endl ;
	}
}

void DLinkedList::removeBack() // 맨 뒤에 원소를 삭제
{
	if( !empty() )
	{
		remove(trailer->prev) ;
	}else
	{
		cout << "Can not remove. Empty" << endl ;
	}
}

bool DLinkedList::empty() const // header와 trailer만 남아 있다면, empty
{
	return (header->next == trailer) ;
}

const Elem& DLinkedList::front() const // 맨 앞의 원소를 반환
{
	return (header->next->elem) ;
}

const Elem& DLinkedList::back() const // 맨 뒤의 원소를 반환
{
	return (trailer->prev->elem) ;
}

class DLLStack
{
public :
	DLLStack() ; // 생성자
	bool empty() const ; // 이 스택이 empty한지 ?
	const Elem& top() const ; // 스택 가장 맨 위에 있는 원소
	void push(const Elem& e) ; // 스택에 맨 위로 push
	void pop() ; // 스택에 top에 있는 원소를 pop
	void judgePM() ; // Parentheses Matching이 correct ? incorrect ?

private :
	DLinkedList DS ; // 이 Stack은 Doubly Linked List를 이용한다.
	int judge ; // correct 여부 (correct : 0, incorrect : 1)
} ;

DLLStack::DLLStack() : DS() // 생성자
{
	judge = 0 ; // 0으로 설정
}

bool DLLStack::empty() const // 이 스택이 empty 한지 ?
{
	return DS.empty() ;
}

const Elem& DLLStack::top() const // 스택 가장 맨 위에 있는 원소
{
	if( !empty() )
	{
		return DS.front() ;
	}else
	{
		return 1 ;
	}
}

void DLLStack::push(const Elem& e) // 맨 위로( Front -> 위로 생각 ) 원소를 삽입
{
	if( e == '(' || e == '{' || e == '[' )
	{
		DS.addFront(e) ;
	}else if( e == ')' )
	{
		if( top() == '(' )
		{
			pop() ;
		}else
		{
			judge = 1 ;
		}
	}else if( e == '}' )
	{
		if( top() == '{' )
		{
			pop() ;
		}else
		{
			judge = 1 ;
		}
	}else if( e == ']' )
	{
		if( top() == '[' )
		{
			pop() ;
		}else
		{
			judge = 1 ;
		}
	}
}

void DLLStack::pop() // 맨 위에( Front -> 위로 생각 ) 원소를 제거
{
	if( !empty() )
	{
		DS.removeFront() ;
	}else
	{
		cout << "Stack is Empty" << endl ;
	}
}

void DLLStack::judgePM() // correct ? incorrect ?
{
	if( judge == 0 && empty() )
	{
		cout << "correct" << endl ;
	}else
	{
		cout << "incorrect" << endl ;
	}
}

int main()
{
	cout << "12141680 Parentheses Matching DLLStack" << endl << endl ;

	int i = 0 ;

	char p1[14] = {'(',')','(','(',')',')','{','(','[','(',')',']',')','}'} ;
	char p2[16] = {'(','(','(',')','(','(',')',')','{','(','[','(',')',']',')','}'} ;
	char p3[13] = {')','(','(',')',')','{','(','[','(',')',']',')','}'} ;
	char p4[6] = {'(','{','[',']',')','}'} ;
	char p5[1] = {'('} ;

	DLLStack DS1 ;
	DLLStack DS2 ;
	DLLStack DS3 ;
	DLLStack DS4 ;
	DLLStack DS5 ;
	DLLStack DS6 ;

	for( i = 0 ; i < 14 ; i++ )
	{
		cout << p1[i] << " " ;
		DS1.push(p1[i]) ;
	}

	cout << " : " ;
	DS1.judgePM() ;
	cout << endl ;

	for( i = 0 ; i < 16 ; i++ )
	{
		cout << p2[i] << " " ;
		DS2.push(p2[i]) ;
	}

	cout << " : " ;
	DS2.judgePM() ;
	cout << endl ;
	
	for( i = 0 ; i < 13 ; i++ )
	{
		cout << p3[i] << " " ;
		DS3.push(p3[i]) ;
	}

	cout << " : " ;
	DS3.judgePM() ;
	cout << endl ;

	for( i = 0 ; i < 6 ; i++ )
	{
		cout << p4[i] << " " ;
		DS4.push(p4[i]) ;
	}

	cout << " : " ;
	DS4.judgePM() ;
	cout << endl ;

	for( i = 0 ; i < 1 ; i++ )
	{
		cout << p5[i] << " " ;
		DS5.push(p5[i]) ;
	}

	cout << " : " ;
	DS5.judgePM() ;
	cout << endl ;

	return 0 ;
}