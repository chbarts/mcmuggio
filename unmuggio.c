#include <string.h>
#include <stdio.h>

static int unmuggio(int c)
{
    return c & 0xfe;
}

int main(int argc, char *argv[])
{
    int i, c;
    FILE *inf;

    if (1 == argc) {
        while ((c = getchar()) != EOF)
            putchar(unmuggio(c));

        fflush(stdout);
        return 0;
    }

    if (2 == argc) {
        if (!strcmp(argv[1], "--help")) {
            puts("unmuggio [files...]");
            puts("unmuggio: Invert a weirdly broken McDonald's receipt machine by setting the low bit to 0");
            puts("MCMUFFIN -> LBLTFFHN");
            return 0;
        } else if (!strcmp(argv[1], "--version")) {
            puts("unmuggio version 1.0");
            return 0;
        }
    }

    for (i = 1; i < argc; i++) {
        if ((inf = fopen(argv[i], "rb")) == NULL) {
            fprintf(stderr, "%s: ", argv[0]);
            perror(argv[i]);
            continue;
        }

        while ((c = getc(inf)) != EOF)
            putchar(unmuggio(c));

        fclose(inf);
    }

    fflush(stdout);
    return 0;
}
