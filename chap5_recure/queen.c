#include <stdio.h>
#include <stdlib.h>

int pos[8];
int flag_a[8] = {
    0,
};
int flag_b[15] = {
    0,
};
int flag_c[15] = {
    0,
};

void print(void)
{
    for (int k = 0; k < 8; k++)
    {
        printf("a%d:%d ", k, flag_a[k]);
    }
    printf("\n");
    for (int k = 0; k < 15; k++)
    {
        printf("b%d:%d ", k, flag_b[k]);
    }
    printf("\n");
    for (int k = 0; k < 15; k++)
    {
        printf("c%d:%d ", k, flag_c[k]);
    }
    printf("\n");
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%2d", pos[i]);
    }
    putchar('\n');
}
void set(int i)
{
    int j;
    for (j = 0; j < 8; j++)
    {
        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
        {
            print();
            pos[i] = j;
            if (i == 7)
            {
                print();
                exit(0);
            }
            else
            {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                set(i + 1);
                printf("\n");
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            }
        }
    }

}

int main(void)
{
    // int x;
    // printf("정수를 입력: ");
    // scanf("%d", &x);

    // printf("%d의 순차곱셈은 %d 입니다.\n",x,factorial(x));
    set(0);
    return 0;
}