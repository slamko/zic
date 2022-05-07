#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errorka.h"

int 
main(int argc, char **argv) {
    char *str = NULL;

    ERR_DEFER(printf("error"))

    str = PTR_UNWRAP (calloc(10, sizeof(*str)))
    DEFER (free(str))
    
    if (strnlen(argv[1], 10) >= 10) {
        ERROR(ERR_USER)
    }

    UNWRAP_PTR(strcpy(str, argv[1]));
    printf("%s", str);

    return OK;
}
