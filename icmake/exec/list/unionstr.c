#include "list.ih"

void list_unionStr(ListVariable *list, char const *str)
{
    if (list_contains(list, str) == -1)
        list_add_charPtr(list, str);
}















