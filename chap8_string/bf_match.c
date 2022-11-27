#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bf_match(const char txt[], const char pat[])
{
    int pt=0;
    int pp=0;
    
    while(txt[pt] != '\0' && pat[pp] != '\0'){
        if(txt[pt]==pat[pp]){
            pt++;
            pp++;
        }
        else{
            pt=pt-pp+1;
            pp=0;
        }
    }
    if(pat[pp]=='\0')
        return pt-pp;
    return -1;
}

int bm_match(const char txt[], const char pat[])
{
    int pt;
    int pp;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    
    int skip[UCHAR_MAX+1]; //255
    for(pt=0;pt<=UCHAR_MAX;pt++)
        skip[pt] = pat_len;
    for(pt=0;pt<pat_len-1;pt++)
        skip[pat[pt]]=pat_len-pt-1;
    
    for(int i=0;i<)
    printf("skip[%d]: %d",)

}


int main(void)
{
    int idx;
    char s1[20];
    char s2[9]={'a','b','a','c','a','a','b','a'};

    printf("%d ", UCHAR_MAX);

    // printf("Text: ");
    // scanf("%s",s1);
    // printf("Pattern: ");
    // scanf("%s",s2);

    // idx = kmp_match(s1,s2);

    
    return 0;
} 