#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_sort(char txt[], char pat[])
{
    int txt_size = strlen(txt);
    int pat_size = strlen(pat);

    //Skip Table     
    int length = pat_size; //NULL 문자 제거
    int skip_table[UCHAR_MAX+1];   //영어 문자열을 length로 초기화
    for(int i=0;i<UCHAR_MAX+1;i++)
    {
        skip_table[i] = length;
    }
    for(int i=0;i<length-1;i++){    //Last Letter은 제외 --> 마지막 배열 전에 Last Letter 문자가 없다면 lenght로 설정됨
        skip_table[(int)pat[i]]=length-i-1;
    }
    for (int i = 0; i < (sizeof(skip_table)/sizeof(int)); i++)  //Skip Table 출력
    {
        if(skip_table[i] !=length)
            printf("skip[%c]=%d ", (char)i, skip_table[i]);
    }
    printf("skip[%c]=%d\n", pat[length-1], skip_table[length-1]);


    int now=pat_size-1; 

    // do{
    //     if(txt[now] != pat[now]){
    //         now = 
    //     }
    //     else{
    //         now--;
    //     }
    // }


}


int main(void)
{
    int idx;
    char s1[20];
    char s2[5]={'c','a','b','c'};
    
    bm_sort(s1,s2);




    
    return 0;
} 