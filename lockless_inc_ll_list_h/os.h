#ifndef __OS_H__
#define __OS_H__

#include "std_types.h"

//MOCKED FUNCTIONS

static inline u32 os_start_critical_section(void)
{
    return 0;
}

static inline void os_end_critical_section(u32 context)
{
    //NOTHING DONE HERE
}
#endif
