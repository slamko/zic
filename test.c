#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errorka.h"

int
main(int argc, char **argv) DEF
    char *str = NULL;

    printf("%d", argc);
    str = PTR_UNWRAP (calloc(10, sizeof(*str)))

    if (argc != 2) {
        ERROR(ERR_USER)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR(ERR_USER)
    }

    UNWRAP_PTR(strcpy(str, argv[1]));
    printf("%s", str);

    OK()
END
