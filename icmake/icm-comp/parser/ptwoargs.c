#include "parser.ih"

SemVal *p_twoArgs(ExprType type, SemVal *larg, SemVal *rarg)
{
    register int ok;

    p_expr2stack(larg);                             /* arg to stack */
    p_expr2stack(rarg);                             /* arg to stack */

    switch ((FunNr)type)
    {
        case f_fgets:
            ok = test_type(larg, e_str) && test_type(rarg, e_list);
        break;

        case f_element:                     /* f_element */
                                            /* first arg must be int */
            if ( (ok = test_type(larg, e_int)) )
            {                               /* second arg == list: ok */
                if (!(ok = test_type(rarg, e_list)))
                {                           /* second arg == string: ok */
                    ok = test_type(rarg, e_str);
                    type = f_str_el;        /* string element requested */
                }
            }
        break;

        case f_resize:
            ok = test_type(larg, e_str) && test_type(rarg, e_int);
        break;

        default:
            /*
                case f_strtok:
                case f_c_ext:
                case f_c_base:
                case f_c_path:
                case f_strfind:
            */
            ok = larg->type & rarg->type & e_str;
    }

    if (ok)
    {
        p_catCode(rarg, larg);                /* make one code vector */
        p_callRss(rarg, type);
    }
    else
    {
        util_semantic(gp_typeConflict, gp_funstring[type]);
        p_discard(larg);
    }
    return (rarg);
}
