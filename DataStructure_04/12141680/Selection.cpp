#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 5000000

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

void SelectionSort(int a[], int n)
{
	int min ;

	for( int i = 0 ; i < n ; i++ )
	{
		min = i ; // 첫 번째 값을 min으로 설정

		for( int j = i + 1 ; j <= n ; j++ )
		{
			if( a[j] < a[min] ) // 그 후 비교하며 제일 작은 값을 min으로 설정
			{
				min = j ;
			}
		}

		swap(a, i, min) ; // min을 앞으로 보냄
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

	start = clock() ; // 선택 정렬 시작
	SelectionSort(p, MAX-1) ; // 선택 정렬 실행
	stop = clock() ; // 선택 정렬 종료

	cout << "12141680 SelectionSort" << endl << endl ;
	
	print_elapsed(start, stop) ; // 경과 시간 출력

	cout << endl ;

	delete p ; // 동적 할당 -> delete
}