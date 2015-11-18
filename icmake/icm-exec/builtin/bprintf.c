/*
    This function prints the arguments to a {\em printf()} statement,
    pushed onto the stack previously. The number of arguments to printf is
    the last pushed value.
*/

/* #define msg
*/

#include "builtin.ih"

void b_printf(void)
{
    msg("called");

    gb_reg = *intcons_int(eb_formattedFprintf(stdout, 1));
}




