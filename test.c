#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zic.h"

result some() DEF
    ERROR(ERR_USER)
END

int
main(int argc, char **argv) DEF
    char *str = NULL;

    printf("%d", argc);
    str = PTR_UNWRAP (calloc(10, sizeof(*str)))

    if (some()) 
        CATCH("wrong name: %s", argv[0])

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
