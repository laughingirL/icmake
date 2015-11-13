#define msg

#include "icmake.ih"

    /* return 1 if -- was encountered, otherwise 0 */
int optChars(char const *program, char const *options, char **argv)
{
    if (strcmp(options, "--") == 0)  
        return 1;

    while (1)                           /* process multiple -xyz args */
    {
        int c;
        switch (c = *++options)
        {
            case 0:
            return 0;

            case 'h':                   /* set flags matching options */
            usage(program);             /* usage requested: provide help */

            case 'a':
                flags |= f_about;
            break;

            case 'b':
                directExecuteOpt(argv[2]);
            break;

            case 'c':
                compileOpt(argv + 1);
            break;

            case 'i':
                imOpt(argv + 1);
            break;

            case 't':
                tmpBimOpt(argv + 1);
            break;

            case 'p':
                preProcessOpt(argv + 1);
            break;

            default:
            rss_error("option -%c not supported", c);
        }
    }
}
