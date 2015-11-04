#include "parser.ih"

SemVal *while_stmnt(SemVal *e, SemVal *s, int pureWhile)
{
    register size_t len;
    unsigned *list;

    gp_nestLevel--;                            /* reduce nesting level */
    gp_breakOK--;                             /* reduce break ok */

    etob(e);                                /* make links for E */

    if (test_type(e, e_const))              /* constant: never xeq */
    {
        if (e->evalue)
            e->evalue = 0;                  /* no value = no code for catcode */
                                            /* MAYBE CODELEN = 0 ?? */
        else
        {
            clearbin(e, s);
            return (e);
        }
    }

    patchup_true(e, 1);                     /* patch to EOC */

    list = e->falselist;
    len  = e->falselen;

    e->falselen = 0;                        /* no more false links avail. */

    catcode(e, s);                          /* append s to e */

    if (pureWhile)                          /* not a while stmd that's part */
        patchup_continue(e, -e->codelen);   /* of a for stmnt               */

    gencode(e, op_jmp, j_falselist);        /* jmp to begin of code */

    patchup_false(e, 0);                    /* patch to BOC */

    e->falselist = list;
    e->falselen = len;

    patchup_true(e, 1);                    /* patchup break targets to EOC */

    return e;
}




