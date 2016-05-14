#include "options.ih"

static struct option longOpts[] = 
{
    {"classes",     required_argument,  NULL, 'c'},
    {"dry",         no_argument,        NULL, 'd'},        // no -d option
    {"go",          no_argument,        NULL, 'g'},        // no -g option
    {"help",        no_argument,        NULL, 'h'},
    {"icmconf",     required_argument,  NULL, 'i'},
    {"mainih",      required_argument,  NULL, 'm'},
    {"gch",         no_argument,        NULL, 'p'},        // no -p option
    {"no-gch",      no_argument,        NULL, 'G'},        // no -G option
    {"use-all",     no_argument,        NULL, 'u'},        // no -u option
    {"no-use-all",  no_argument,        NULL, 'U'},        // no -U option
    {"verbose",     no_argument,        NULL, 'V'},
    {"version",     no_argument,        NULL, 'v'},
    {NULL}
};

Options s_Options;

void OptionsCons(int argc, char **argv)
{
    regComp(&s_Options.icmconfRE, 
            "^[ \t]*#define[ \t]*"
                    "([^ \t]+)"     //      #1: key 
                    "[ \t]*\""
                    "([^\"]+)?"     //      #2: value (opt)
                    "\"");        

    s_Options.classes    = "CLASSES";
    s_Options.icmconf    = "icmconf";
    s_Options.mainih     = "main.ih";
    s_Options.ih         = ".ih";

    int showVersion = 0;

    while (1)
    {
        int opt = getopt_long(argc, argv, "cdimhvV", longOpts, NULL);

        switch (opt)
        {
            case 'c':
                s_Options.classes = rss_strdup(optarg);
            break;

            case 'd':
                s_Options.dry = 1;
            break;

            case 'g':
                s_Options.go = 1;
            break;

            case 'p':
                s_Options.gch = 1;
            break;

            case 'G':
                s_Options.gch = 0;
            break;

            case 'h':
                usage(argv[0]);
            break;                  // usage exits

            case 'i':
                s_Options.icmconf = rss_strdup(optarg);
            break;

            case 'm':
                s_Options.mainih = rss_strdup(optarg);
            break;

            case 'u':
                s_Options.no_use_all = 0;
            break;

            case 'U':
                s_Options.no_use_all = 1;
            break;

            case 'v':
                showVersion = 1;
            break;

            case 'V':
                ++s_Options.verbose;
            break;

            case '?':
                printf("no option '-%c'\n", (char)opt);
                exit(1);
            break;

            case -1:
                if (showVersion)
                {
                    printf("V %s\n", version);
                    exit(0);
                }

                if (s_Options.go == 0 && s_Options.dry == 0)
                    usage(argv[0]);

                if (s_Options.dry)
                    s_Options.go = 0;

                oIcmconf();

            return;
        }
    }
}
