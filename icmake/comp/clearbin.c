/*
                                C L E A R B I N . C
*/

#include "iccomp.h"

void clearbin(ESTRUC_ *lval, ESTRUC *rval)
{
    discard(rval);
    discard(lval);
    memset(lval, 0, sizeof(ESTRUC_));
    lval->type = e_int | e_const;
}
