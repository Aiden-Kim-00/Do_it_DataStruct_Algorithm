#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
    IntQueue s;
    if(Initialize(&s,3)==-1)
    {
        puts("init fail");
        return 1;
    }

    while (1)
    {
        int menu, x;
        printf("current data num: %d / %d\n",Size(&s), Capacity(&s));
        printf("1:push 2:pop 3:peak 4:printf 0:terminate : ");
        scanf("%d", &menu);

        if(menu==0) break;
        switch (menu)
        {
        case 1:
            printf("data: ");
            scanf("%d",&x);
            if(Enque(&s, x)==-1)
                puts("\aerror! Push fail");
            break;
        case 2:
            if(Deque(&s, &x)==-1)
                puts("\aerror! Pop fail");
            else    
                printf("pop data is %d\n", x);
            break;
        case 3:
            if(Peek(&s, &x)==-1)
                puts("\aerror! Peak fail");
            else
                printf("peak data is %d\n", x);
            break;
        case 4:
            Print(&s);
            break;

        default:
            break;
        }
        
        /* code */
    }
    Terminate(&s);
    return 0;
}