#include <stdio.h>
#include "ll_list.h"
#if 0
Example program shows various usage of ll_list.h macros and functions.
#endif

typedef struct MY_STRUCT MY;
struct MY_STRUCT {
    dlist LP;
    int val;
};

void scanning_forward(dlist *headp);
void scanning_backward(dlist *headp);

int main(void)
{
    MY my[8];
    MY xmy = {.val = -10};
    DLIST_HEAD(myhead);

    printf("Add elements to end of list\n");
    for(int i=0; i <8; i++){
        my[i].val = (i * i) + 1;
        dlist_add_end(&myhead, &my[i].LP);
        MY *myptr = (MY *)(myhead.next);
    }
    scanning_forward(&myhead);
    scanning_backward(&myhead);

    printf("\nAdd elements to start of list\n");
    dlist_init(&myhead);
    for(int i=0; i <8; i++){
        my[i].val = (i * i) + 1;
        dlist_add(&myhead, &my[i].LP);
    }
    scanning_forward(&myhead);
    scanning_backward(&myhead);

    printf("\nAdd xmp node after my[4]");
    dlist_add(my[4].LP.next, &xmy.LP);
    scanning_forward(&myhead);
    scanning_backward(&myhead);

    printf("\nRemove xmy node from list\n");
    dlist_del(&xmy.LP);
    scanning_forward(&myhead);

    printf("\nRemove front node from list\n");
    dlist_del(myhead.next);
    scanning_forward(&myhead);

    printf("\nRemove end node from list\n");
    dlist_del(myhead.prev);
    scanning_forward(&myhead);

    return 0;
}
//////////////////////////////////////////////////////////////////////////////
void scanning_forward(dlist *headp)
{
    dlist *iter;
    dlist *tmp;
    printf("Scanning List Forward\n");
    scan_list_safe(headp, iter, tmp)
    {
        MY *myptr= list_entry(MY, LP, iter);
        printf("%d ", myptr->val);
    }
}

void scanning_backward(dlist *headp)
{
    dlist *iter;
    dlist *tmp;

    printf("\nScanning List Backward\n");
    scan_dlist_reverse_safe(headp, iter, tmp)
    {
        MY *myptr= list_entry(MY, LP, iter);
        printf("%d ", myptr->val);
    }
}
