#include <stdio.h>
#include <stdlib.h>

//이진 검색

int bin_search(int list_[],int key, int cnt){
    int pl=0;
    int pr = cnt-1;
    int pc =0;
    while(pl <= pr)
    {
        pc = (pl+pr)/2;
        if(list_[pc] == key)
        {
            return pc;
        }
        else if(list_[pc] > key)
        {
            pr = pc-1;
        }
        else
        {
            pl = pc + 1;
        }
    }
    return -1;

}

int main(void){
    int n;
    int *list;
    int temp=0;
    int s=0;
    int get=0;

    printf("n: "); 
    scanf("%d",&n);

    list = (int*)calloc(n, sizeof(int));

    for(int i=0;i<n;i++)
    {
        printf("list[%d]: ",i);
        scanf("%d",&list[i]);
    }  

    printf("search: ");
    scanf("%d",&s);

    get = bin_search(list, s, n);
    if(get == -1)
    {
        printf("no exist\n");
    }

    else
    {  
        printf("%d is list[%d]\n",s,get);
    }

    free(list);
}