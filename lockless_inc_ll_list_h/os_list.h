#ifndef __OS_LIST_H__
#define __OS_LIST_H__

#include "os.h"
#include "ll_list.h"

//These provide atomic access to the dlist.
static inline dlist *os_dlist_get_head(dlist *d)
{
    u32 context = os_start_critical_section();
    if(d == d->prev)
    {
        os_end_critical_section(context);
        return NULL;
    }
    dlist *t = d->next;
    dlist_del(d->next);
    os_end_critical_section(context);
    return t;
}

static inline dlist *os_dlist_get_tail(dlist *d)
{
    u32 context = os_start_critical_section();
    if(d == d->prev)
    {
        os_end_critical_section(context);
        return NULL;
    }
    dlist *t = d->prev;
    dlist_del(d->prev);
    os_end_critical_section(context);
    return t;
}

static inline void os_dlist_put_head(dlist *d, dlist *a)
{
    u32 context = os_start_critical_section();
    dlist_add(d, a);
    os_end_critical_section(context);
}

static inline void os_dlist_put_tail(dlist *d, dlist *a)
{
    u32 context = os_start_critical_section();
    dlist_add(d->prev, a);
    os_end_critical_section(context);
}

#endif
