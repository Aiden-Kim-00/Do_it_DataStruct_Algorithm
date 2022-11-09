#include <stdio.h>
#include <stdlib.h>
// 선형검색 + 보초법

int search_al(const int list_[], int key, int cnt){
    int i=0;
    while(1)
    {
        if(list_[i] == key)
        {
            return i;
        }
        i++;
        if(i==cnt)
        {
            return -1;
        }
    }
}


int main(){
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

    get = search_al(list, s,n);

    if(get)
    {  
        printf("%d is list[%d]\n",s,get);
    }
    else 
    {
        printf("no exist\n");
    }

    free(list);



}