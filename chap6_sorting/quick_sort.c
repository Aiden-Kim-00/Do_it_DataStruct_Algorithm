#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

int cnt_a=0;
int cnt_b=0;


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


void quick_sort(int a[], int left, int right)
{

    int pl=left;
    int pr=right;
    int x=a[(pl+pr)/2];   //pivot

    while(pl<=pr)
    {
        while(a[pl]<x)
        {
            pl++;
        }
        while(a[pr]>x)
        {
            pr--;
        }
        if(pl<=pr)  //end
        {
            swap(int,a[pl],a[pr]);
            pl++;
            pr--;
        }
    }
    if(left<pr) quick_sort(a,left,pr);
    if(pl<right) quick_sort(a,pl,right);

    // printf("pivot=%d\n",x);
    // printf("pivot or less: ");
    // for(i=0;i<=pl-1;i++)
    //     printf("%d ",a[i]);
    // printf("\n");

    // printf("equal to pivot: ");
    // for(i=pr+1;i<pl-1;i++)
    //     printf("%d ",a[i]);
    // printf("\n");

    // printf("pivot or more: ");
    // for(i=pr+1;i<=n-1;i++)
    //     printf("%d ",a[i]);
    // printf("\n");
}

void quick_sort_stack(int a[], int left, int right)
{
    IntStack lstack;
    IntStack rstack;

    Initialize(&lstack,right-left+1);
    Initialize(&rstack,right-left+1);

    Push(&lstack, left);
    Push(&rstack, right);

    while (!IsEmpty(&lstack))
    {
        int pl = (Pop(&lstack, &left),left);
        int pr = (Pop(&rstack, &right),right);
        int x = a[(left + right) / 2]; // pivot

        while (pl <= pr)
        {
            while (a[pl] < x)
            {
                pl++;
            }
            while (a[pr] > x)
            {
                pr--;
            }
            if (pl <= pr) // end
            {
                printf("a\n");
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        }

        if (left < pr)    
        {
            Push(&lstack,left);
            Push(&rstack,pr);
        }

        if (pl < right)    
        {
            Push(&lstack,pl);
            Push(&rstack,right);
        }
    }

    Terminate(&lstack);
    Terminate(&rstack);
}




int main(void)
{
    int i, nx;
    int *x, *y;

    int aa[9]={0,};

    printf("arr num: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
        // y[i] = x[i];
    }

    // quick_sort(x, nx);

    
    quick_sort_stack(x, 0, nx-1);

    for (i = 0; i < 9; i++)
    {
        printf("x[%d] = %d ", i,x[i]);
    }
    printf("\n");

    free(x);

    return 0;
}