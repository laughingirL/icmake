#include "iccomp.h"

void patchtrue(ESTRUC_ *e)
{                                           /* expand the truelist */
    e->truelist = xrealloc(e->truelist, (e->truelen + 1) * sizeof(size_t));

                                            /* room for the jump-backpatch */
    e->code = xrealloc(e->code, e->codelen += sizeof(INT16));
    e->truelist[e->truelen++] = e->codelen;   /* store jumpstart location */
}
