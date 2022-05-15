#include <stdio.h>
#include <stdlib.h>

#define RTSZ(i) RTSZ1(i, __LINE__)
#define RTSZ1(i, l) RTSZ2(i, l)
#define RTSZ2(i, l) RTSZ_##i##_##l

#define GOTOC(i) goto RTSZ(i);

#define DEFER1(LABEL, ST) goto next##LABEL; defer##LABEL: ST; goto exit; next##LABEL:;
#define DEFER2(ST) goto next1; defer1: goto defer1; ST; goto exit; next1:;

#define ERR_CLEANUP(LABEL) goto defer##LABEL;

int some() {
    void *some = malloc(10);
    DEFER1(freesome, free(some))

    ERR_CLEANUP(freesome)

    exit:
    return 1;
}