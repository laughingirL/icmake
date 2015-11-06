/*
                            D I V I D E . C
*/

#include "parser.ih"

SemVal *divide(SemVal *lval, SemVal *rval)
{
    if (test_binop(op_div, lval, rval))
        return (lval);                      /* test for correct types */

    btoi(lval);                             /* convert pending booleans */
    btoi(rval);

    if (conflict(lval, rval, op_div))       /* test type conflict */
        return(lval);

    if (test_type(rval, e_const))
    {
        if (!rval->evalue)                  /* expression / 0: not allowed */
        {
            util_semantic("division by 0: undefined");
            clearbin(lval, rval);
            return (lval);
        }
        if (test_type(lval, e_const))
        {
            lval->evalue /= rval->evalue;
            return (lval);
        }
    }

    defcode(lval, rval, op_div);
    return (lval);                          /* return new expression */
}
