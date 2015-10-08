#include <stdio.h>
#include "os_list.h"

typedef struct MY_STRUCT MY;
struct MY_STRUCT {
    dlist LP;
    int val;
};

int main(void)
{
    MY my[8];
    DLIST_HEAD(myhead);
    dlist *dt;

    printf("stack style\n");
    for(int i=0; i <8; i++){
        my[i].val = i;
        os_dlist_put(&myhead, &my[i].LP);
    }

    while(dt = os_dlist_get(myhead.next))
    {
        MY *tp = list_entry(MY, LP, dt);
        printf("%d ",  tp->val);
    }

    printf("\nfifo style\n");
    for(int i=0; i <8; i++){
        my[i].val = i;
        os_dlist_put(&myhead, &my[i].LP);
    }

    while(dt = os_dlist_get(myhead.prev))
    {
        MY *tp = list_entry(MY, LP, dt);
        printf("%d ",  tp->val);
    }
    return 0;
}
