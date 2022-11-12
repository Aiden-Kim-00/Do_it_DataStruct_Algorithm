#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

static int *buff;

void heatsort(int a[], int n)
{
    //초기에 전체 배열을 힙 구조로 만들기(힙 크기는 감소하지 않음=최대힙)
    for(int i=1;i<n;i++)    
    {
        int c=i;
        do{
            int root = (c-1)/2;
            if(a[root] < a[c])  //자신의 부모 < 자식
            {
                swap(int, a[root],a[c]);
            }
            c=root;
        }while(c!=0);
    } 
    // 크기를 줄여가며 반복적으로 힙 구성
    for(int k=n-1;k>=0;k--)    //k=10
    {
        swap(int, a[0],a[k]);
        int root=0;
        int c=1;
        do{
            c=2*root + 1;   //왼쪽 자식
            if(a[c]<a[c+1] && c<k-1)
            {
                c++;
            }
            if(a[root] < a[c] && c<k)  //자신의 부모 < 자식
            {
                swap(int, a[root],a[c]);
            }
            root = c;
        }while(c<k);

    }
}

int main(void)
{
    int i, na,nb;
    int *a,*b,*c;

    printf("a arry num: ");
    scanf("%d", &na);
    a = calloc(na, sizeof(int));
    for (i = 0; i < na; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    mergesort(a,na);




    puts("Up Sorting");
    for (i = 0; i < na; i++)
    {
        printf("[%d] = %d ", i,a[i]);
    }
    printf("\n");

    free(a);
    free(b);
    free(c);


    return 0;

}