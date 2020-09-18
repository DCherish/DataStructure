#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 5000000

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

void SelectionSort(int a[], int n)
{
	int min ;

	for( int i = 0 ; i < n ; i++ )
	{
		min = i ; // ù ��° ���� min���� ����

		for( int j = i + 1 ; j <= n ; j++ )
		{
			if( a[j] < a[min] ) // �� �� ���ϸ� ���� ���� ���� min���� ����
			{
				min = j ;
			}
		}

		swap(a, i, min) ; // min�� ������ ����
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

	start = clock() ; // ���� ���� ����
	SelectionSort(p, MAX-1) ; // ���� ���� ����
	stop = clock() ; // ���� ���� ����

	cout << "12141680 SelectionSort" << endl << endl ;
	
	print_elapsed(start, stop) ; // ��� �ð� ���

	cout << endl ;

	delete p ; // ���� �Ҵ� -> delete
}