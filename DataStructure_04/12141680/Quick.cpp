#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 1000000

using namespace std ;

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed ; ���� ~ ��, ��� �ð�
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // ��� �ð��� ��� (sec)
}

void swap(int a[], int p, int q) // ������ ���� swap a[p] <-> a[q]
{
	int temp ;

	temp = a[p] ;
	a[p] = a[q] ;
	a[q] = temp ;
}

void MTQuickSort(int a[], int l, int r)
{
	int i, j, m, v ;
	if( r - l > 1 ) // ���� right > left
	{
		m = (l + r) / 2 ; // middle = (left + right) / 2
		
		if( a[l] > a[m] ) // ���� left > middle
		{
			swap(a, l, m) ; // swap left <-> middle
		}

		if( a[l] > a[r] ) // if left > right
		{
			swap(a, l, r) ; // swap left <-> right
		}

		if( a[m] > a[r] ) // if middle > right
		{
			swap(a, m, r) ; // swap middle <-> right
		}

		swap(a, m, r-1) ; // swap middle <-> right-1

		v = a[r-1] ;
		i = l ; // i = left index
		j = r - 1 ; // j = right-1 index

		for(;;)
		{
			while( a[++i] < v ) ; // left ����
			while( a[--j] > v ) ; // right ����
			if( i >= j ) break ; // ���� i >= j, break
			swap(a, i, j) ; // swap i <-> j
		}

		swap(a, i, r-1) ; // swap i <-> right-1
		MTQuickSort(a, l, i-1) ; // i-1 -> right
		MTQuickSort(a, i+1, r) ; // i+1 -> left

	}else if( a[l] > a[r] ) // if left > right
	{
		swap(a, l, r) ; // swap left <-> right
	}
}

int main()
{
	clock_t start, stop ;

	int *p = new int[MAX] ; // ���� �Ҵ�, ������ ���� Ȯ���ϱ� ����

	srand((unsigned)time(NULL)) ; // ���� �� ���� �ٸ� random �� �� �߻� (������ ����)

	for( int i = 0 ; i < MAX ; i++ )
	{
		p[i] = rand() ; // ���� -> p �迭 ����
	}

	start = clock() ; // �� ���� ����
	MTQuickSort(p, 0, MAX-1) ; // �� ���� ����
	stop = clock() ; // �� ���� ����

	cout << "12141680 QuickSort" << endl << endl ;

	print_elapsed(start, stop) ; // ��� �ð� ���

	cout << endl ;

	delete p ; // ���� �Ҵ� -> delete

	return 0 ;
}