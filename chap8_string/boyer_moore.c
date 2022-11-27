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

    // for (int i = 0; i < (sizeof(skip_table)/sizeof(int)); i++)  //Skip Table 출력
    // {
    //     if(skip_table[i] !=length)
    //         printf("skip[%c]=%d ", (char)i, skip_table[i]);
    // }
    // printf("skip[%c]=%d\n", pat[length-1], skip_table[(int)pat[length-1]]);


    // Boyer-Moore 알고리즘 수행
    int txt_now=pat_size-1; 
    int pat_now=pat_size-1;    
    while(pat_now!=-1){     
        if(txt[txt_now] != pat[pat_now]){
            txt_now += skip_table[(int)txt[txt_now]];
            pat_now=pat_size-1;
            if(txt_now > txt_size)
                return -1;
        }
        else{
            txt_now--;
            pat_now--;
        }
    }
    return txt_now +1;
}


int main(void)
{
    int idx;
    char txt[256];
    char pattern[256];

    puts("Boyer-Moore Algorithm");
    printf("txt: ");
    scanf("%s",txt);
    printf("pattern: ");
    scanf("%s",pattern);

    int result = bm_sort(txt,pattern);
    if(result == -1)
    {
        printf("patter is no exist in txt\n");
    }
    else{
        printf("search position: %d\n", result);
    }

    return 0;
} 