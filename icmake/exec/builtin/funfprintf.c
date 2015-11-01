/*
\funcref{fun\_fprintf}{void fun\_fprintf ()}
    {}
    {}
    {fprintf(), xrealloc()}
    {fun\_exec()}
    {funfprin.c}
    {

        This function prints the arguments to a {\em fprint()} statement,
        pushed onto the stack previously. The number of arguments to print is
        the last pushed value.

        The arguments are: the number of arguments (a hidden parameter), a
        filename, and then the remaining arguments to print.

    }

*/

#include "builtin.ih"

void fun_fprintf()
{
    char const *filename = stringStr(top() - 1);
    FILE *outf;

    if (! (outf = fopen(filename, "a")) )
        error("failure to open file \"%s\"", filename);

    formatedFprintf(outf, 2);

    fclose (outf);
}







