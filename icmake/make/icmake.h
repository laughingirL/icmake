#include "../rss/icrssdef.h"

#ifdef MSDOS
#   define __STDC__
#   define ICMCOMP          "icm-comp.exe"
#   define ICMEXEC          "icm-exec.exe"
#   define ICMPP            "icm-pp.exe"
#elif 0
#   define ICMEXEC          "/usr/lib/icmake/icm-exec"
#   define ICMCOMP          "/usr/lib/icmake/icm-comp"
#   define ICMPP            "/usr/lib/icmake/icm-pp"
#else
#   define ICMEXEC          "bin/icm-exec"
#   define ICMCOMP          "bin/icm-comp"
#   define ICMPP            "bin/icm-pp"
#endif

#ifdef SUN
#include <memory.h>
#endif


typedef enum
{
    f_preprocessor  =   (1 << 0),
    f_compiler      =   (1 << 1),
    f_quiet         =   (1 << 2),
    f_redirected    =   (1 << 3),
    f_blunt         =   (1 << 4),
    f_icmake        =   (1 << 5),
    f_tmpbim        =   (1 << 6),
} FLAGS_;

extern char
    version[],
    release[],
    cant_read[],
    r[],
    rb[];

extern char *temporary;
extern char *source_name;
extern char *dest_name;

extern FILE
    *fdest;

extern FLAGS_
    flags;

extern int
    errors;

extern size_t
    redirect_nr;

int     compile_test ARG((void));           /* test if compilation is needed */
int     options ARG((char **, int*));       /* process flags */

void    abnormal_exit ARG((int));          /* abnormal eop */
void    about(void);                        /* about icmake */
void    cleanup ARG((void));                /* cleanup temp. info */
void    quote_blanks(char **);              /* quote arguments with blanks */
