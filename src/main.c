#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

bool verbose = false;

static const struct option long_opts[] = {
    {"help", no_argument, NULL, 'h'},
    {"verbose", no_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}
};

static const char *opts_desc[] = {
    "to display this usage message",
    "for verbose output",
};

static void usage(char const * const progname)
{
    printf("usage: %s [OPTIONS] PORT, where\n", progname);
    printf("  OPTIONS:\n");
    for (int i = 0; i < sizeof(long_opts) / sizeof(struct option) - 1; ++i)
        printf("\t-%c, --%s, %s\n",
               long_opts[i].val, long_opts[i].name, opts_desc[i]);
    exit(0);
}

int main(int argc, char * const argv[])
{
    int opt;
    uint16_t port;

    while (-1 != (opt = getopt_long(argc, argv, "hv", long_opts, NULL))) {
        switch (opt) {
        case 'h':
            usage(argv[0]);
        case 'v':
            verbose = true;
            break;
        default:
            fprintf(stderr, "invalid option: %c\n", opt);
            usage(argv[0]);
        }
    }

    if (argc - optind != 1)
        usage(argv[0]);

    port = (uint16_t)atoi(argv[optind]);
    if (port == 0) { // atoi() returns 0 and sets errno on error
        fprintf(stderr, "invalid port: %s\n", argv[optind]);
        usage(argv[0]);
    }

    if (verbose)
        printf("listening on port %d\n", port);

    // proxy goes here

    return 0;
}
