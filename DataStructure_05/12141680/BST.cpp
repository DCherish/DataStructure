#include <iostream>
#include <queue>

using namespace std ;

class BST
{
	struct Node
	{
		int element ;
		Node* left ;
		Node* right ;
	} ;

	Node* root ;

	Node* makeEmpty(Node* t) // 모든 BST안의 노드를 삭제
	{
		if( t == NULL ) return NULL ;
		{
			makeEmpty(t->left) ;
			makeEmpty(t->right) ;
			delete t ;
		}
		return NULL ;
	}

	Node* insert(int key, Node* t) // key값을 비교하며 BST안에 노드를 삽입
	{
		if( t == NULL )
		{
			t = new Node ;
			t->element = key ;
			t->left = t->right = NULL ;
		}else if( key < t->element ) // key 값이 parent 보다 작으면
		{
			t->left = insert(key, t->left) ; // left child에 삽입
		}else if( key > t->element ) // key 값이 parent 보다 크다면
		{
			t->right = insert(key, t->right) ; // right child에 삽입
		}

		return t ;
	}

	Node* findMin(Node* t) // 노드 삭제 시 inorder 후행자를 찾아나서는 모습
	{
		if( t == NULL ) return NULL ;
		else if( t->left == NULL )
		{
			return t ;
		}else
		{
			return findMin(t->left) ;
		}
	}

	Node* findMax(Node* t) // 노드 삭제 시 inorder 선행자를 찾아나서는 모습
	{
		if( t == NULL ) return NULL ;
		else if( t->right == NULL )
		{
			return t ;
		}else
		{
			return findMax(t->right) ;
		}
	}

	Node* remove(int key, Node* t) // 노드 삭제
	{
		Node* temp ;

		if( t == NULL ) return NULL ;
		else if( key < t->element )
		{
			t->left = remove(key, t->left) ;
		}else if( key > t->element )
		{
			t->right = remove(key, t->right) ;
		}else if( t->left && t->right )
		{
			temp = findMin(t->right) ;
			t->element = temp->element ;
			t->right = remove(t->element, t->right) ;
		}else
		{
			temp = t ;
			if( t->left == NULL ) t = t->right ;
			else if( t->right == NULL )
			{
				t = t->left ;
			}
			delete temp ;
		}

		return t ;
	}

	void showtree(Node* t) // 트리 모양 출력
	{
		if( t == NULL )	return ;

		int arr[100] = {0} ;
		int count = 1 ;

		queue<Node*> a ; // queue를 이용, BFS 개념을 응용

		a.push(t) ;

		arr[count] = t->element ;

		while( !a.empty() )
		{
			Node *n = a.front() ;
			a.pop() ;

			if( n->left != NULL ) // 왼쪽부터 읽기 위해 왼쪽 자식부터 queue에 삽입
			{
				count++ ;
				arr[count] = n->left->element ;
				a.push(n->left) ;
			}

			if( n->right != NULL )
			{
				count++ ;
				arr[count] = n->right->element ;
				a.push(n->right) ;
			}
		}

		int h = 0 ;
		int tf ;

		int rt = arr[1] ;

		cout << "< Tree >" << endl ;

		cout << "Height " << h << " : " << rt ;
		h++ ;
		
		for( int i = 2 ; i <= count ; i++ )
		{
			if( arr[i-1] < rt )
			{
				if( rt < arr[i] ) rt = arr[i] ;
				tf = 1 ;
			}else if( rt < arr[i] )
			{
				rt = arr[i] ;
				tf = 0 ;
				cout << endl ;
			}
			
			if( arr[i-1] > arr[i] )
			{
				tf = 0 ;
				cout << endl ;
			}

			if( tf == 0 )
			{
				cout << "Height " << h << " : " ;
				h++ ;
				tf = 1 ;
			}

			cout << arr[i] << " " ;			
		}
	}

	void preorder(Node* t) // preorder ( D L R )
	{
		if( t == NULL ) return ;
		cout << t->element << " " ;
		preorder(t->left) ;
		preorder(t->right) ;
	}

	void inorder(Node* t) // inorder ( L D R )
	{
		if( t == NULL ) return ;
		inorder(t->left) ;
		cout << t->element << " " ;
		inorder(t->right) ;
	}

	void postorder(Node* t) // postorder ( L R D )
	{
		if( t == NULL ) return ;
		postorder(t->left) ;
		postorder(t->right) ;
		cout << t->element << " " ;
	}

	Node* find(Node* t, int x)
	{
		if(t == NULL) return NULL ;
		else if( x < t->element )
		{
			return find(t->left, x) ;
		}else if( x > t->element )
		{
			return find(t->right, x) ;
		}else
		{
			return t ;
		}
	}

public :
	BST()
	{
		root = NULL ;
	}

	~BST()
	{
		root = makeEmpty(root) ;
	}

	void insert(int x)
	{
		root = insert(x, root) ;
	}

	void remove(int x)
	{
		root = remove(x, root) ;
	}

	void showtree()
	{
		showtree(root) ;
		cout << endl ;
	}

	void preorder()
	{
		preorder(root) ;
		cout << endl ;
	}

	void inorder()
	{
		inorder(root) ;
		cout << endl ;
	}

	void postorder()
	{
		postorder(root) ;
		cout << endl ;
	}

	void search(int x)
	{
		root = find(root, x) ;

		if( root == NULL )
		{
			cout << "There is NO " << x << endl ;
		}else
		{
			cout << "There is " << x << endl ;
		}
	}
} ;

int main()
{
	cout << "12141680 김지훈 BST" << endl << endl ;

	BST bst ;
		
	cout << "Insert 20 25 15 10" << endl << endl ;
	bst.insert(20) ;
	bst.insert(25) ;
	bst.insert(15) ;
	bst.insert(10) ;
	bst.showtree() ;

	cout << endl << "Insert 9 11 17 16 18 22 30" << endl << endl ;

	bst.insert(9) ;
	bst.insert(11) ;
	bst.insert(17) ;
	bst.insert(16) ;
	bst.insert(18) ;
	bst.insert(22) ;
	bst.insert(30) ;
	bst.showtree() ;

	cout << "< ↑ BST preorder >" << endl ;
	bst.preorder() ;
	cout << "< ↑ BST inorder >" << endl ;
	bst.inorder() ;
	cout << "< ↑ BST postorder >" << endl ;
	bst.postorder() ;

	cout << endl << "Remove 15" << endl << endl ;

	bst.remove(15) ;
	bst.showtree() ;

	cout << "< ↑ BST preorder >" << endl ;
	bst.preorder() ;
	cout << "< ↑ BST inorder >" << endl ;
	bst.inorder() ;
	cout << "< ↑ BST postorder >" << endl ;
	bst.postorder() ;

	cout << endl << "In TREE, Is there 10 ?" << endl ;
	bst.search(10) ;

	cout << endl << "In TREE, Is there 19 ?" << endl ;
	bst.search(19) ;

	return 0 ;
}
