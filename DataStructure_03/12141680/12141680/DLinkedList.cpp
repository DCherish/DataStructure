#include <iostream>
#include <string.h>

using namespace std ;

typedef int Elem ; // Elem들은 int형
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
	const Elem& showfromfront() const ; // header -> trailer 방향으로 원소들을 출력
	const Elem& showfromback() const ; // trailer -> header 방향으로 원소들을 출력
	const Elem& front() const ; // 맨 앞의 원소 (header -> next)
	const Elem& back() const ; // 맨 뒤의 원소 (trailer -> prev)
	void addFront(const Elem& e) ; // 맨 앞에 원소를 추가 (header -> next)
	void addBack(const Elem& e) ; // 맨 뒤에 원소를 추가 (trailer -> prev)
	void removeFront() ; // 맨 앞쪽 원소를 제거 (header -> next)
	void removeBack() ; // 맨 뒤쪽 원소를 제거 (trailer -> prev)

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

const Elem& DLinkedList::showfromfront() const // header -> trailer 출력
{
	DNode *v = header ;

	while( v->next != trailer )
	{
		cout << v->next->elem << " " ;
		v = v->next ;
	}

	cout << endl ;

	return (header->next->elem) ;
}

const Elem& DLinkedList::showfromback() const // trailer -> header 출력
{
	DNode *v = trailer ;

	while( v->prev != header )
	{
		cout << v->prev->elem << " " ;
		v = v->prev ;
	}

	cout << endl ;

	return (trailer->prev->elem) ;
}

const Elem& DLinkedList::front() const // 맨 앞의 원소를 반환
{
	return (header->next->elem) ;
}

const Elem& DLinkedList::back() const // 맨 뒤의 원소를 반환
{
	return (trailer->prev->elem) ;
}

int main()
{
	cout << "12141680 Doubly Linked List" << endl << endl ;

	DLinkedList DLL ; // Doubly Linked List 생성

	DLL.addFront(3) ; // 3
	DLL.addFront(4) ; // 4 + 3 -> 4 3
	DLL.addFront(5) ; // 5 + 4 3 -> 5 4 3
	DLL.addFront(6) ; // 6 + 5 4 3 -> 6 5 4 3

	DLL.showfromfront() ; // print " 6 5 4 3 "
	DLL.removeFront() ; // (6) 5 4 3 -> 5 4 3
	DLL.showfromback() ; // 5 4 3 -> print " 3 4 5 "
	DLL.removeBack() ; // 5 4 (3) -> 5 4
	DLL.addBack(7) ; // 5 4 + 7 -> 5 4 7
	DLL.addBack(9) ; // 5 4 7 + 9 -> 5 4 7 9
	DLL.addFront(1) ; // 1 + 5 4 7 9 -> 1 5 4 7 9
	DLL.showfromfront() ; // print " 1 5 4 7 9 "

	for( int i = 0 ; i < 5 ; i++ ) // remove all in list
	{
		DLL.removeBack() ;
	}

	DLL.removeFront() ; // list empty -> error
	DLL.removeBack() ; // lst empty -> error

	DLL.addFront(3) ; // 3
	DLL.addBack(5) ; // 3 + 5 -> 3 5
	DLL.addBack(7) ; // 3 5 + 7 -> 3 5 7

	DLL.showfromfront() ; // print " 3 5 7 "
	
	cout << endl ;
	
	return 0 ;
}