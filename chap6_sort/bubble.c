#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

int cnt_a=0;
int cnt_b=0;

void bubble(int a[], int n) //기본 버블정렬
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = n-1; j > i; j--)
        {
            cnt_a++;
            if (a[j-1] > a[j])  //교환
            {
                swap(int, a[j-1], a[j]);
            }
        }
    }
}

void bubble_2(int a[], int n)   //정렬이 끝나면 바로 끝나는 알고리즘
{
    int i, j;
    
    for (i = 0; i < n-1; i++)
    {
        int exchg=0;
        for (j = n-1; j > i; j--)
        {
            cnt_a++;
            if (a[j-1] > a[j])  //교환
            {
                exchg++;
                swap(int, a[j-1], a[j]);
            }
        }
        if(exchg==0) break;
    }
}

void bubble_3(int a[], int n)   //정렬이 끝나면 바로 끝나는 알고리즘 + 첫정렬에서 끝난 부분 배제
{
    int i=0;
    int j=0;
    while (i < n-1)
    {
        int last = n-1;
        for (j = n-1; j > i; j--)
        {
            cnt_a++;
            if (a[j-1] > a[j])  //교환
            {
                last = j;
                swap(int, a[j-1], a[j]);
            }
        }
        i = last;
    }
}

void bubble_4(int a[], int n)   //정렬이 끝나면 바로 끝나는 알고리즘 + 첫정렬에서 끝난 부분 배제 + 칵테일 정렬
{
    int left=0;
    int right=n-1;
    
    int last = right;
    
    while (left < right)
    {
        int j=0;
        for (j = right; j > left; j--)
        {
            cnt_b++;
            if (a[j-1] > a[j])  //교환
            {
                last = j;
                swap(int, a[j-1], a[j]);
            }
        }
        left = last;

        for(j=left; j<right;j++)
        {
            cnt_b++;
            if (a[j] > a[j+1])  //교환
            {
                last = j;
                swap(int, a[j], a[j+1]);
            }
        }
        right = last;
    }


}

int is_sorted(const int a[],int n){
    int i;
    for (i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int i, nx;
    int *x, *y;

    printf("arr num: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    y = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
        y[i] = x[i];
    }
    
    bubble_3(x, nx);
    bubble_4(y, nx);
    

    // printf("finish: %d\n",is_sorted(x,nx));
    printf("comp x: %d\n", cnt_a);
    printf("comp y: %d\n", cnt_b);
    
    free(x);

    return 0;
}