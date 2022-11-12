#include <stdio.h>
#include <stdlib.h>

static int *buff;



void hearsort(int a[], int n)
{
    int i;
    
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