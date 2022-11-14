#include <stdio.h>
#include <stdlib.h>

static int *buff;

void distributionsort(int a[], int n)
{
    int i;
    int *f, *b;
    int max=0;
    for(i=0;i<n;i++)
    {
        if(max<a[i])
            max = a[i]+1;
    }
    f = calloc(max,sizeof(int));
    b = calloc(n,sizeof(int));

    for(i=0;i<n;i++)
    {
        f[a[i]]++;
    }

    for(i=1;i<max;i++)
    {
        f[i] = f[i]+f[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        b[f[a[i]]-1]=a[i];
        f[a[i]]--;
    }

    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }


    free(f);
    free(b);



    
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

    distributionsort(a,na);     //범위 조건 있음


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