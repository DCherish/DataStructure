---

<div align="center">

 💜 *DataStructure Assignment*

</div>

---

# 👨‍💻 공통 사용 기술 Stack
- [x] Visual Studio 

---

# 🧐 [SNS 주소 관리 프로그램 (#A1)](https://github.com/DCherish/DataStructure/tree/master/DataStructure_01)  
- 위 프로그램은 주소의 등록, 삭제, 검색 등의 기능을 가짐  
- 부모클래스를 설계하고 이를 상속받은 2개 이상의 자식클래스를 설계  
- 또 다시 이 자식 클래스를 상속받은 자식 클래스를 1개 이상 설계  
- overloading 메소드가 하나 이상 되도록 설계  
  - 하나 이상의 virtual function, virtual destructor, 함수 template을 작성  
  - polymorphism을 보여줄 수 있는 응용을 설계, 동적바인딩이 되는 예를 제시   

# ⌨️ Code (일부분)
```c++  
class SNSAdrs
{
private:
	char* address[10]; // 받아온 주소들을 저장하는 배열
	int index;

protected:
	int count; // 각각 현재 저장된 주소 개수 = count

public:
	SNSAdrs(); // 생성자
	virtual ~SNSAdrs() {}; // virtual destructor
	void insadrs(char* a); // 주소를 입력받는 기능의 함수
	void deladrs(char* a); // 입력받은 주소를 삭제하는 기능의 함수
	int findadrs(char* a); // 삭제할 때 주소가 존재하는 지 찾아보는 함수
	void searchadrs(char* a); // 주소를 검색하는 기능의 함수
	virtual void howmanyadrs() = 0; // virtual function (pure virtual function)
};
```  
> SNSADRS.h 일부분  

<br/>

```c++  
class CSAdrs : public SNSAdrs // 클래스를 상속 받음 (부모 클래스 : SNSAdrs, 자식 클래스 : CSAdrs)
{
private:
	string text;
	int ccount; // CSAdrs 클래스의 주소 개수

public:
	CSAdrs() {}; // 생성자
	~CSAdrs() {}; // 소멸자
	void howmanyadrs(); // 현재 주소 개수 몇개 있는지를 출력 (부모 클래스에서 virtual function으로 선언)
	void sendmessage(int i); // overloading 함수(메소드), 변수 ; int 형
	void sendmessage(string s); // overloading 함수(메소드), 변수 ; string 형
};
```  
> CHATSNS.h 일부분  

# 💛 프로젝트 결과 (간략)
<img src="/image/d1.png" width="450px" height="300px" alt="BlockDiagram"></img><br/>
> Class Diagram of SNS Address Management Program  

<br/>

<img src="/image/d7.png" width="450px" height="auto" alt="BlockDiagram"></img><br/>
> SNS 주소 관리 프로그램 실행 결과 창 (일부분)  

---

# 🧐 [ArrayStack 구현 및 표기식 변환 (#A2)](https://github.com/DCherish/DataStructure/tree/master/DataStructure_02)  
- ArrayStack을 구현하여 중위 표기식을 후위 표기식으로 변환하는 프로그램을 작성  

# ⌨️ Code (일부분)
```c++  
template <typename E>
class ArrayStack // ArrayStack 클래스 선언
{
	enum { DEF_CAPACITY = 100 }; // default 선언

private:
	E* S;
	int capacity;
	int t;

public:
	ArrayStack(int cap = DEF_CAPACITY); // default 생성자
	ArrayStack(const ArrayStack& a); // 복사 생성자
	~ArrayStack(); // 소멸자
	int size() const; // 스택에 저장된 원소들의 갯수
	bool empty() const; // 스택이 비었는지 판단
	const E& top() const throw(StackEmpty); // 스택 내의 가장 top 부분의 원소 반환
	void push(const E& e) throw(StackFull); // 최상위 스택 원소 저장
	void pop() throw(StackEmpty); // 최상위 스택 원소 삭제
	int PIS(const E& e) const; // 스택내의 우선순위
	int PIE(const E& e) const; // 수식내의 우선순위
	void postfix(E* exp, int n);
};
```  
> ArrayStack.h 일부분  

<br/>

```c++  
int main()
{
	ArrayStack<string> A;

	const int z1 = 6;
	string zz1[z1] = { "A", "*", "B", "*", "C", "@" };
	cout << "1) : ";
	A.postfix(zz1, z1);
	cout << endl << endl;

	const int z2 = 18;
	string zz2[z2] = { "(", "(", "A", "+", "(", "B", "*", "C", ")", ")", "-", "(", "D", "/", "E", ")", ")", "@" };
	cout << "2) : ";
	A.postfix(zz2, z2);
	cout << endl << endl;

	const int z3 = 9;
	string zz3[z3] = { "-", "A", "+", "B", "-", "C", "+", "D" , "@" };
	cout << "3) : ";
	A.postfix(zz3, z3);
	cout << endl << endl;
	// 중략...
}
```  
> INtoPOST.cpp 일부분  

# 💛 프로젝트 결과 (간략)
<img src="/image/d2.png" width="450px" height="300px" alt="BlockDiagram"></img><br/>
> Infix ➡️ Postfix (Convert Notation)  

---

# 🧐 [Doubly Linked List 구현 및 응용 Stack 구현 (#A3)](https://github.com/DCherish/DataStructure/tree/master/DataStructure_03)  
- Doubly Linked List를 구현한 후 이를 이용해 스택을 구현하여 괄호 매칭 프로그램을 작성  

# ⌨️ Code (일부분)
```c++  
class DLinkedList
{
public:
	DLinkedList(); // 생성자
	~DLinkedList(); // 소멸자
	bool empty() const; // List가 empty한지 ?
	const Elem& showfromfront() const; // header -> trailer 방향으로 원소들을 출력
	const Elem& showfromback() const; // trailer -> header 방향으로 원소들을 출력
	const Elem& front() const; // 맨 앞의 원소 (header -> next)
	const Elem& back() const; // 맨 뒤의 원소 (trailer -> prev)
	void addFront(const Elem& e); // 맨 앞에 원소를 추가 (header -> next)
	void addBack(const Elem& e); // 맨 뒤에 원소를 추가 (trailer -> prev)
	void removeFront(); // 맨 앞쪽 원소를 제거 (header -> next)
	void removeBack(); // 맨 뒤쪽 원소를 제거 (trailer -> prev)

private:
	DNode* header;
	DNode* trailer;

protected:
	void add(DNode* v, const Elem& e);
	void remove(DNode* v);
};
// 중략...
int main()
{
	DLinkedList DLL; // Doubly Linked List 생성

	DLL.addFront(3); // 3
	DLL.addFront(4); // 4 + 3 -> 4 3
	DLL.addFront(5); // 5 + 4 3 -> 5 4 3
	DLL.addFront(6); // 6 + 5 4 3 -> 6 5 4 3

	DLL.showfromfront(); // print " 6 5 4 3 "
	DLL.removeFront(); // (6) 5 4 3 -> 5 4 3
	DLL.showfromback(); // 5 4 3 -> print " 3 4 5 "
	DLL.removeBack(); // 5 4 (3) -> 5 4
	DLL.addBack(7); // 5 4 + 7 -> 5 4 7
	DLL.addBack(9); // 5 4 7 + 9 -> 5 4 7 9
	DLL.addFront(1); // 1 + 5 4 7 9 -> 1 5 4 7 9
	// 중략...
}
```  
> DLinkedList.cpp 일부분  

<br/>

```c++  
class DLLStack
{
public:
	DLLStack(); // 생성자
	bool empty() const; // 이 스택이 empty한지 ?
	const Elem& top() const; // 스택 가장 맨 위에 있는 원소
	void push(const Elem& e); // 스택에 맨 위로 push
	void pop(); // 스택에 top에 있는 원소를 pop
	void judgePM(); // Parentheses Matching이 correct ? incorrect ?

private:
	DLinkedList DS; // 이 Stack은 Doubly Linked List를 이용한다.
	int judge; // correct 여부 (correct : 0, incorrect : 1)
};
// 중략...
int main()
{
	char p1[14] = { '(',')','(','(',')',')','{','(','[','(',')',']',')','}' };
	// 중략...
	DLLStack DS1;
	// 중략...
	for (i = 0; i < 14; i++)
	{
		cout << p1[i] << " ";
		DS1.push(p1[i]);
	}

	cout << " : ";
	DS1.judgePM();
	cout << endl;
	// 중략...
}
```  
> P-MatchingDLL.cpp 일부분  

# 💛 프로젝트 결과 (간략)
<img src="/image/d8.png" width="450px" height="300px" alt="BlockDiagram"></img><br/>
> Doubly Linked List 구현 실행 결과 창  

<br/>

<img src="/image/d3.png" width="450px" height="300px" alt="BlockDiagram"></img><br/>
> 괄호 매칭 프로그램 실행 결과 창  

---

# 🧐 [정렬 알고리즘 구현 및 분석 (#A4)](https://github.com/DCherish/DataStructure/tree/master/DataStructure_04)  
- **정렬 알고리즘** 중 3가지의 알고리즘을 구현한 후 분석  
  - `SelectionSort` `MergeSort` `QuickSort`  

# ⌨️ Code (일부분)
```c++  
void SelectionSort(int a[], int n)
{
	int min;

	for (int i = 0; i < n; i++)
	{
		min = i; // 첫 번째 값을 min으로 설정

		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[min]) // 그 후 비교하며 제일 작은 값을 min으로 설정
			{
				min = j;
			}
		}

		swap(a, i, min); // min을 앞으로 보냄
	}
}
```  
> Selection.cpp 일부분  

<br/>

```c++  
void MergeSort(int a[], int l, int r)
{
	int mid;

	if (l < r)
	{
		mid = (l + r) / 2;

		MergeSort(a, l, mid); // divide
		MergeSort(a, mid + 1, r); // divide

		Merge(a, l, r, mid); // conquer
	}
}
```  
> Merge.cpp 일부분  

<br/>

```c++  
void MTQuickSort(int a[], int l, int r)
{
	{
	// 중략...
		v = a[r - 1];
		i = l; // i = left index
		j = r - 1; // j = right-1 index

		for (;;)
		{
			while (a[++i] < v); // left 증가
			while (a[--j] > v); // right 감소
			if (i >= j) break; // 만약 i >= j, break
			swap(a, i, j); // swap i <-> j
		}

		swap(a, i, r - 1); // swap i <-> right-1
		MTQuickSort(a, l, i - 1); // i-1 -> right
		MTQuickSort(a, i + 1, r); // i+1 -> left

	}
	// 중략...
}
```  
> Quick.cpp 일부분  

# 💛 프로젝트 결과 (간략)
<img src="/image/d4.png" width="650px" height="250px" alt="BlockDiagram"></img><br/>
<img src="/image/d5.png" width="450px" height="390px" alt="BlockDiagram"></img><br/>
> 세 가지의 정렬 알고리즘 성능 비교  
👉 QuickSort < MergeSort << SelectionSort  

---

# 🧐 [Binary Search Tree 구현 (#A5)](https://github.com/DCherish/DataStructure/tree/master/DataStructure_05)  
- BST의 경우, insert 정상 작동 여부 및 preorder, inorder, postorder 방문 순서를 출력  

# ⌨️ Code (일부분)
```c++  
class BST
{
	struct Node
	{
		int element;
		Node* left;
		Node* right;
	};

	Node* root;
  
	// 중략...
  
	void preorder(Node* t) // preorder ( D L R )
	{
		if (t == NULL) return;
		cout << t->element << " ";
		preorder(t->left);
		preorder(t->right);
	}
  
	// 중략...
};

int main()
{
	BST bst;
	
	// 중략...
	bst.insert(10);
	bst.showtree();

	// 중략...
	bst.insert(30);
	bst.showtree();

	bst.preorder();
	bst.inorder();
	bst.postorder();

	bst.remove(15);
	bst.showtree();

	bst.search(10);
	// 중략...
}

```  
> BST.cpp 일부분  

# 💛 프로젝트 결과 (간략)
<img src="/image/d6.png" width="450px" height="300px" alt="BlockDiagram"></img><br/>
> Binary Search Tree 실행 결과 창
