#include "iccomp.h"

ESTRUC_ *nullframe(ESTRUC_ *e)
{
    discard(e);
    *e = *stackframe(0);
    return e;
}
