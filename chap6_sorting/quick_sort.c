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


void quick_sort(int a[], int n)
{
    int i,j,h;
    int pl=0;
    int pr=n-1;
    int x=a[n/2];   //pivot

    while(pl<=pr)
    {
        while(a[pl]<x)
        {
            pl++;
        }
        while(a[pr]>x)
        {
            pr++;
        }
        if(pl<=pr)  //end
        {
            swap(int,a[pl],a[pr]);
            pl++;
            pr++;
        }
    }

        printf("pivot=%d\n",x);
        printf("pivot or less: ");
        for(i=0;i<pl-1;i++)
            printf("%d ",a[i]);
        printf("\n");
        
        printf("equal to pivot: ");
        for(i=pr+1;i<pl-1;i++)
            printf("%d ",a[i]);
        printf("\n");

        printf("pivot or more: ");
        for(i=pr+1;i<n-1;i++)
            printf("%d ",a[i]);
        printf("\n");
    
}


int main(void) 
{
    int i, nx;
    int *x, *y;

    printf("arr num: ");
    // scanf("%d", &nx);
    // x = calloc(nx, sizeof(int));
    // // y = calloc(nx, sizeof(int));

    // for (i = 0; i < nx; i++)
    // {
    //     printf("x[%d] = ", i);
    //     scanf("%d", &x[i]);
    //     // y[i] = x[i];
    // }

    // quick_sort(x, nx);
   


    // for (i = 0; i < nx; i++)
    // {
    //     printf("x[%d] = %d", i,x[i]);
    // }
    // printf("\n");

    // printf("comp x: %d\n", cnt_a);
    // printf("comp y: %d\n", cnt_b);
    
    // free(x);

    return 0;
}