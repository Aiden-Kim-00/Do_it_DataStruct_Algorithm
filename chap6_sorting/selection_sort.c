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

void shell(int a[], int n)
{
    int i,j,h;
    h=n/2;

    for(i=1;i<n;i++)
    {
        int tmp = a[i];
        for(j=i;j>0 && a[i-1]>tmp ; j--)
        {
            a[j] = a[j-1];
        }
        a[j] =tmp;
    }

    h=n/2;

    for(i=0;i<1;i++)
    {
        int tmp = a[0+4];
        for(j=1;j>0 && a[i-1]>tmp ; j--)
        {
            a[j] = a[j-1];
        }
        a[j] =tmp;
    }

h = n/2;//4
    
    for(h=1;h<n/9;h=h*3+1);
    
    for(;h>0;h=h/3)  //4-2-1
    {
        for(i=h;i<h;i++)
        { 
            int tmp = a[i];
            for(j=i-h;j>0&&a[j]>tmp;j-=h)
            {
                a[j+h] = a[j];
            }
            a[j+h] = tmp;
        }

    }


    for(i=0;i<4;i++)
    {
        int tmp = a[i+4];
        for(j=i+4;j>0 && a[i]>tmp ; j-=4)
        {
            a[i+4] = a[i];
        }
        a[i] =tmp;
    }

    for(i=0;i<7;i++)
    {
        int tmp = a[i+2];
        for(j=i+2;j>0 && a[j]>tmp ; j-=2)
        {
            a[j+2] = a[j];
        }
        a[i] =tmp;
    }



    for(i=1;i<8;i++)
    {
        int tmp = a[i];
        for(j=i;j>0 && a[j]>tmp ; j--)
        {
            a[j+1] = a[j];
        }
        a[i] =tmp;
    }


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