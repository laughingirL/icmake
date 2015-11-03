#include "parser.ih"

void defcode(SemVal *lval, SemVal *rval, OPCODE_ opcode)
{
    etoc(lval);                     /* convert to code */
    etoc(rval);
    catcode(lval, rval);
    gencode(lval, opcode);          /* append instruction */
    set_type(lval, e_int | e_code); /* set appropriate type */
}
