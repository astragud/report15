#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 난수 배열 크기
#define SIZE 20

int com = 0, swaps = 0;

// 배열 요소 교환 함수
static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 셸 정렬 함수
static void shellSort(int list[], int k)
{
    int gap, i, j, temp, comparisons = 0, moves = 0;
    if (k == 0)
    {
        printf("shell sort\n");
    }

    // 셸 정렬에 사용할 간격(gap) 설정
    for (gap = SIZE / 2; gap > 0; gap /= 2)
    {
        // 삽입 정렬 수행
        for (i = gap; i < SIZE; i++)
        {
            temp = list[i];
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap)
            {
                // 비교 횟수 증가
                comparisons++;
                // 값 이동
                moves++;
                list[j] = list[j - gap];
            }
            // 비교 횟수 증가
            comparisons++;
            // 값을 올바른 위치에 삽입
            list[j] = temp;
        }

        // 정렬 결과 출력
        if (k == 0)
        {
            for (i = 0; i < SIZE; i++)
            {
                printf("%d ", list[i]);
            }
            printf("\n");
        }    
    }
    com = com + comparisons;
    swaps = swaps + moves;
}

int main()
{
    int list[SIZE]{};
    srand(time(NULL));

    for (int j = 0; j < 19; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            list[i] = rand() % 100;
        }

        if (j == 0)
        {
            // 초기 배열 출력
            printf("초기 배열\n");
            for (int i = 0; i < SIZE; i++)
            {
                printf("%d ", list[i]);
            }
            printf("\n\n");
        }

        // 셸 정렬 수행
        shellSort(list, j);
    }

    printf("average compare count  : %d\n", com / 20);
    printf("average move count  : %d\n", swaps / 20);
    return 0;
}