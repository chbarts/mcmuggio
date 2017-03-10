#include <string.h>
#include <stdio.h>

static int muggio(int c)
{
    return c | 1;
}

int main(int argc, char *argv[])
{
    int i, c;
    FILE *inf;

    if (1 == argc) {
        while ((c = getchar()) != EOF)
            putchar(muggio(c));

        return 0;
    }

    if (2 == argc) {
        if (!strcmp(argv[1], "--help")) {
            puts("mcmuggio [files...]");
            puts("mcmuggio: Emulate a weirdly broken McDonald's receipt machine by setting the low bit to 1");
            puts("MCMUFFIN -> MCMUGGIO");
            return 0;
        } else if (!strcmp(argv[1], "--version")) {
            puts("mcmuggio version 1.0");
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
            putchar(muggio(c));

        fclose(inf);
    }

    return 0;
}
