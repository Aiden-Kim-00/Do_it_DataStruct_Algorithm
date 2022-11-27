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

void bubble(int a[], int n)
{
    int i, j;
    for (i = n-1; i > 0; i--)
    {
        printf("path %d\n",n-i);
        for (j = 0; j < i-1; j++)
        {
            cnt_a++;    //비교
            if (a[j] > a[j+1])  //교환
            {
                for(int k=0;k<n;k++){
                    printf(" %d",a[k]);
                    if(k==j){printf("+");}
                    else printf(" ");
                }
                printf("\n");
                cnt_b++;    //교환
                swap(int, a[j], a[j+1]);
            }
            else    //교환x
            {
                for(int k=0;k<n;k++){
                    printf(" %d",a[k]);
                    if(k==j){printf("-");}
                    else printf(" ");
                }
                printf("\n");
            }
        }
        printf("\n\n");
    }
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

    bubble(x, nx);

    puts("finish");
    printf("comp: %d\n", cnt_a);
    printf("swap: %d\n", cnt_b);
    free(x);

    return 0;
}