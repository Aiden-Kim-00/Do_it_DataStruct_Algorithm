#include <stdio.h>
#include <stdlib.h>

static int *buff;

void merge(const int a[], int na, const int b[], int nb, int c[], int nc)
{
    int pa=0;
    int pb=0;
    int pc=0;

    while(pa<na && pb<nb)
    {
        c[pc++] = (a[pa]<=b[pb]) ? a[pa++] : b[pb++];
    }
    while (pa<na)
    {
        c[pc++] = a[pa++];
    }
    while (pb<nb)
    {
        c[pc++] = b[pb++];
    }
}


static void _mergesort(int a[], int left, int right)
{
    if(left < right)
    {
        int p=0;
        int i;
        int j=0;
        int k=left;
        int center = (left + right)/2;
        _mergesort(a,left,center);  //front 
        _mergesort(a,center+1,right);  //back 
        for(i=left;i<=center;i++)
            buff[p++]=a[i];
        while(i<=right && j<p)
            a[k++]=(buff[j]<=a[i]) ? buff[j++] : a[i++];
        while(j<p)
            a[k++] = buff[j++];
    }
}

void mergesort(int a[], int n)
{
    buff = calloc(n,sizeof(int));
    _mergesort(a, 0, n-1);
    free(buff);
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


/*
    printf("b arry num: ");
    scanf("%d", &nb);
    b = calloc(nb, sizeof(int));
    for (i = 0; i < nb; i++)
    {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    c = calloc(na+nb, sizeof(int));

    merge(a,na,b,nb,c,na+nb);
*/



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