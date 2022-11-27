#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n>0)
    {
        return n*factorial(n-1);
    }
    else
        return 1;
}

int gcd(int x, int y){
    if(y==0)
        return x;
    else
        return gcd(y, x%y);
}

int main(void){
    int x;
    printf("정수를 입력: ");
    scanf("%d", &x);

    printf("%d의 순차곱셈은 %d 입니다.\n",x,factorial(x));
    return 0;
}