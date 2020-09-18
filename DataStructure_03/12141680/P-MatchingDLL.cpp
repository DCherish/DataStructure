#include <iostream>
#include <string.h>

using namespace std ;

typedef char Elem ; // Elem���� char��
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
	const Elem& front() const ; // �� ���� ���� (header -> next)
	const Elem& back() const ; // �� ���� ���� (trailer -> prev)
	void addFront(const Elem& e) ; // �� �տ� ���Ҹ� �߰� (header -> next)
	void addBack(const Elem& e) ; // �� �ڿ� ���Ҹ� �߰� (trailer -> prev)
	void removeFront() ; // �� ���� ���Ҹ� ���� (header -> next)
	void removeBack() ; // �� ���� ���Ҹ� ���� (trailer -> prev)

	friend class DLLStack ; // Doubly Linked List�� ������ Stack

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

const Elem& DLinkedList::front() const // �� ���� ���Ҹ� ��ȯ
{
	return (header->next->elem) ;
}

const Elem& DLinkedList::back() const // �� ���� ���Ҹ� ��ȯ
{
	return (trailer->prev->elem) ;
}

class DLLStack
{
public :
	DLLStack() ; // ������
	bool empty() const ; // �� ������ empty���� ?
	const Elem& top() const ; // ���� ���� �� ���� �ִ� ����
	void push(const Elem& e) ; // ���ÿ� �� ���� push
	void pop() ; // ���ÿ� top�� �ִ� ���Ҹ� pop
	void judgePM() ; // Parentheses Matching�� correct ? incorrect ?

private :
	DLinkedList DS ; // �� Stack�� Doubly Linked List�� �̿��Ѵ�.
	int judge ; // correct ���� (correct : 0, incorrect : 1)
} ;

DLLStack::DLLStack() : DS() // ������
{
	judge = 0 ; // 0���� ����
}

bool DLLStack::empty() const // �� ������ empty ���� ?
{
	return DS.empty() ;
}

const Elem& DLLStack::top() const // ���� ���� �� ���� �ִ� ����
{
	if( !empty() )
	{
		return DS.front() ;
	}else
	{
		return 1 ;
	}
}

void DLLStack::push(const Elem& e) // �� ����( Front -> ���� ���� ) ���Ҹ� ����
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

void DLLStack::pop() // �� ����( Front -> ���� ���� ) ���Ҹ� ����
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