#include <iostream>
#include <string.h>

using namespace std ;

typedef int Elem ; // Elem���� int��
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
	DLinkedList() ; // ������
	~DLinkedList() ; // �Ҹ���
	bool empty() const ; // List�� empty���� ?
	const Elem& showfromfront() const ; // header -> trailer �������� ���ҵ��� ���
	const Elem& showfromback() const ; // trailer -> header �������� ���ҵ��� ���
	const Elem& front() const ; // �� ���� ���� (header -> next)
	const Elem& back() const ; // �� ���� ���� (trailer -> prev)
	void addFront(const Elem& e) ; // �� �տ� ���Ҹ� �߰� (header -> next)
	void addBack(const Elem& e) ; // �� �ڿ� ���Ҹ� �߰� (trailer -> prev)
	void removeFront() ; // �� ���� ���Ҹ� ���� (header -> next)
	void removeBack() ; // �� ���� ���Ҹ� ���� (trailer -> prev)

private :
	DNode *header ;
	DNode *trailer ;

protected :
	void add(DNode *v, const Elem& e) ;
	void remove(DNode *v) ;
} ;

DLinkedList::DLinkedList() // header�� trailer�� ���� �ÿ��� ���ΰ� ���θ� ����Ű�� ����
{
	header = new DNode ;
	trailer = new DNode ;
	header->next = trailer ;
	trailer->prev = header ;
}

DLinkedList::~DLinkedList() // �� ���ʺ��� ��� ���Ҹ� ���� ��, header �� trailer ����
{
	while( !empty() ) removeFront() ;
	delete header ;
	delete trailer ;
}

void DLinkedList::add(DNode *v, const Elem& e) // �� ��� ����, �� ��� �ٷ� ������ �߰�
{
	DNode *u = new DNode ;
	u->elem = e ;
	u->next = v ;
	u->prev = v->prev ;
	v->prev->next = u ;
	v->prev = u ;
}

void DLinkedList::addFront(const Elem& e) // �� �տ� ���Ҹ� �߰�
{
	add(header->next, e) ;
}

void DLinkedList::addBack(const Elem& e) // �� �ڿ� ���Ҹ� �߰�
{
	add(trailer, e) ;
}

void DLinkedList::remove(DNode *v) // �� ��� ����, �� ��� �� �ڳ��� ���� �� �ڽ��� ����
{
	DNode *u = v->prev ;
	DNode *w = v->next ;
	u->next = w ;
	w->prev = u ;

	delete v ;
}

void DLinkedList::removeFront() // �� ���� ���Ҹ� ����
{
	if( !empty() )
	{
		remove(header->next) ;
	}else
	{
		cout << "Can not remove. Empty" << endl ;
	}
}

void DLinkedList::removeBack() // �� �ڿ� ���Ҹ� ����
{
	if( !empty() )
	{
		remove(trailer->prev) ;
	}else
	{
		cout << "Can not remove. Empty" << endl ;
	}
}

bool DLinkedList::empty() const // header�� trailer�� ���� �ִٸ�, empty
{
	return (header->next == trailer) ;
}

const Elem& DLinkedList::showfromfront() const // header -> trailer ���
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

const Elem& DLinkedList::showfromback() const // trailer -> header ���
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

const Elem& DLinkedList::front() const // �� ���� ���Ҹ� ��ȯ
{
	return (header->next->elem) ;
}

const Elem& DLinkedList::back() const // �� ���� ���Ҹ� ��ȯ
{
	return (trailer->prev->elem) ;
}

int main()
{
	cout << "12141680 Doubly Linked List" << endl << endl ;

	DLinkedList DLL ; // Doubly Linked List ����

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