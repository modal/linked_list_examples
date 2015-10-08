#ifndef __OS_LIST_H__
#define __OS_LIST_H__

//#include "os.h"
#include "ll_list.h"

//These provide atomic access to the dlist, assuming the critical sections are
//in place.
static inline dlist *os_dlist_get(dlist *d)
{
    //u32 context = os_start_critical_section();
    if(d == d->prev) return NULL;
    dlist *t = d;
    dlist_del(d);
    return d;
    //os_end_critical_section(context);
}

static inline dlist os_dlist_put(dlist *d, dlist *a)
{
    //u32 context = os_start_critical_section();
    dlist_add(d, a);
    //os_end_critical_section(context);
}

#endif
