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

void Merge(int a[], int l, int r, int m)
{
	int i, j, k ;

	int *temp = new int[r-l+1] ;

	i = l ;
	k = 0 ;
	j = m + 1 ;

	while( i <= m && j <= r ) // 두 개의 그룹을 비교 > 작은 값을 temp로 넣기
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

	while( i <= m ) // 만약 왼쪽 그룹에 값이 남아있다면
	{
		temp[k] = a[i] ; // 나머지를 다 temp로 추가
		k++ ;
		i++ ;
	}

	while( j <= r ) // 만약 오른쪽 그룹에 값이 남아있다면
	{
		temp[k] = a[j] ; // 나머지를 다 temp로 추가
		k++ ;
		j++ ;
	}

	for( i = l ; i <= r ; i++ )
	{
		a[i] = temp[i-l] ; // temp에 있는 값을 다시 a배열로 넣기
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

	int *p = new int[MAX] ; // 동적 할당, 데이터 셋을 확장하기 위함

	srand((unsigned)time(NULL)) ; // 실행 시 마다 다른 random 한 값 발생 (음수는 제외)

	for( int i = 0 ; i < MAX ; i++ )
	{
		p[i] = rand() ; // 난수 -> p 배열 삽입
	}

	start = clock() ; // 합병 정렬 시작
	MergeSort(p, 0, MAX-1) ; // 합병 정렬 실행
	stop = clock() ; // 합병 정렬 종료

	cout << "12141680 MergeSort" << endl << endl ;

	print_elapsed(start, stop) ; // 경과 시간 출력

	cout << endl ;

	delete p ; // 동적 할당 -> delete

	return 0 ;
}