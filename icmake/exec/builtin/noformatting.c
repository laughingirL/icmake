#include "builtin.ih"

void noFormatting(void *dest, size_t start, size_t lastIdx)
{
    listIndex = 0;
    for (size_t idx = start; idx != lastIdx; ++idx)
        writeArgument(dest, idx);
}
