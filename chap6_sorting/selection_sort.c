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

void straight_selection(int a[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i;j<n-1;j++)
        {
            cnt_a++;
            if(a[min] > a[j])
            {
                min=j;
            }
        }
        swap(int, a[min], a[i]);
        
    }
}

void straight_insertion(int a[], int n)
{
    int i,j;
    int tmp;
    int min=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            tmp = a[i+1];
            for(j=i+1;j>0;j--)
            {
                if(tmp > a[j-1])
                {
                    min = j;
                    break;
                }
                else
                {
                    a[j] = a[j-1];
                }
            }
            a[min] = tmp;
        }
        for (int k = 0; k < n; k++)
        {
            printf("a[%d] =%d ", k, a[k]);
        }
        printf("\n");
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
    // y = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
        // y[i] = x[i];
    }

    straight_insertion(x, nx);
   
    // printf("finish: %d\n",is_sorted(x,nx));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = %d", i,x[i]);
    }
    printf("\n");

    printf("comp x: %d\n", cnt_a);
    printf("comp y: %d\n", cnt_b);
    
    free(x);
    free(x);

    return 0;
}