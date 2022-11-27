#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    if(*a<*b)
        return -1;  // 1:내림차순  -1:오름차순
    else if(*a>*b)
        return 1;   //-1:내림차순  1:오름차순
    else   
        return 0;
}

int main(void)
{
    int i, nx;
    int *x;

    printf("arr num: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
    }

    qsort(x,nx,sizeof(int),(int(*)(const void *, const void*))int_cmp);

    puts("Up Sorting");
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = %d ", i,x[i]);
    }
    printf("\n");
    free(x);

    return 0;
}