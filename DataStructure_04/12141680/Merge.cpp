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

void Merge(int a[], int l, int r, int m)
{
	int i, j, k ;

	int *temp = new int[r-l+1] ;

	i = l ;
	k = 0 ;
	j = m + 1 ;

	while( i <= m && j <= r ) // �� ���� �׷��� �� > ���� ���� temp�� �ֱ�
	{  
		if( a[i] < a[j] )
		{
			temp[k] = a[i] ;
			k++ ;
			i++ ;
		}else
		{
			temp[k] = a[j] ;
			k++ ;
			j++ ;
		}
	}

	while( i <= m ) // ���� ���� �׷쿡 ���� �����ִٸ�
	{
		temp[k] = a[i] ; // �������� �� temp�� �߰�
		k++ ;
		i++ ;
	}

	while( j <= r ) // ���� ������ �׷쿡 ���� �����ִٸ�
	{
		temp[k] = a[j] ; // �������� �� temp�� �߰�
		k++ ;
		j++ ;
	}

	for( i = l ; i <= r ; i++ )
	{
		a[i] = temp[i-l] ; // temp�� �ִ� ���� �ٽ� a�迭�� �ֱ�
	}
}

void MergeSort(int a[], int l, int r)
{
	int mid ;

	if( l < r )
	{
		mid = (l + r) / 2 ;

		MergeSort(a, l, mid) ; // divide
		MergeSort(a, mid + 1, r) ; // divide

		Merge(a, l, r, mid) ; // conquer
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

	start = clock() ; // �պ� ���� ����
	MergeSort(p, 0, MAX-1) ; // �պ� ���� ����
	stop = clock() ; // �պ� ���� ����

	cout << "12141680 MergeSort" << endl << endl ;

	print_elapsed(start, stop) ; // ��� �ð� ���

	cout << endl ;

	delete p ; // ���� �Ҵ� -> delete

	return 0 ;
}