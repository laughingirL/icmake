#include "builtin.ih"

void formatedFprintf(FILE *out, size_t start)
{
    p_destWrite = fileWrite;
    formatter(out, start);
}
