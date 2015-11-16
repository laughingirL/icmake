/*
\funcref{fun\_g\_ext}{void fun\_g\_ext ()}
    {}
    {}
    {newvar(), get\_ext ()}
    {fun\_g\_path(), fun\_g\_base()}
    {fungext.c}
    {

        The last pushed string is taken as a file name. The extension is
        returned.

    }
*/

#include "builtin.ih"

void builtin_extension ()
{
    gb_reg = *stringcons_charPtr(rss_getExt(string_charp(stack_top())));
}
