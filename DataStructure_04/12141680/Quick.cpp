#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 1000000

using namespace std ;

void print_elapsed(clock_t start, clock_t stop)
{
	double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC ; // elapsed ; 시작 ~ 끝, 경과 시간
	cout << "Elapsed time : " << elapsed << "sec" << endl ; // 경과 시간을 출력 (sec)
}

void swap(int a[], int p, int q) // 서로의 값을 swap a[p] <-> a[q]
{
	int temp ;

	temp = a[p] ;
	a[p] = a[q] ;
	a[q] = temp ;
}

void MTQuickSort(int a[], int l, int r)
{
	int i, j, m, v ;
	if( r - l > 1 ) // 만약 right > left
	{
		m = (l + r) / 2 ; // middle = (left + right) / 2
		
		if( a[l] > a[m] ) // 만약 left > middle
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
			while( a[++i] < v ) ; // left 증가
			while( a[--j] > v ) ; // right 감소
			if( i >= j ) break ; // 만약 i >= j, break
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

	int *p = new int[MAX] ; // 동적 할당, 데이터 셋을 확장하기 위함

	srand((unsigned)time(NULL)) ; // 실행 시 마다 다른 random 한 값 발생 (음수는 제외)

	for( int i = 0 ; i < MAX ; i++ )
	{
		p[i] = rand() ; // 난수 -> p 배열 삽입
	}

	start = clock() ; // 퀵 정렬 시작
	MTQuickSort(p, 0, MAX-1) ; // 퀵 정렬 실행
	stop = clock() ; // 퀵 정렬 종료

	cout << "12141680 QuickSort" << endl << endl ;

	print_elapsed(start, stop) ; // 경과 시간 출력

	cout << endl ;

	delete p ; // 동적 할당 -> delete

	return 0 ;
}