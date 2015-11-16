/*
\funcref{fun\_g\_path}{void fun\_g\_path ()}
    {}
    {}
    {newvar(), get\_path ()}
    {fun\_g\_ext(), fun\_g\_base()}
    {fungpath.c}
    {

        The last pushed string is taken as a file name. The path is
        returned.

    }
*/

#include "builtin.ih"

void builtin_path ()
{
    gb_reg = *stringcons_charPtr(rss_getPath(string_charp(stack_top())));
}
