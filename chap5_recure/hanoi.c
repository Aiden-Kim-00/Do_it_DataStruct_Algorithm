#include <stdio.h>
#include <stdlib.h>

void move(int no, int x, int y){
    if(no>1)
        move(no-1,x,6-x-y);
    printf("[%d] is moved %d to %d\n",no,x,y);

    if(no>1)
        move(no-1,6-x-y,y);
}

int main(void){
    int n;
    printf("no: ");
    scanf("%d", &n);

    move(n,1,3);

    return 0;
}