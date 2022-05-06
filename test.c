#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errorka.h"

//void *unwrap_ptr_res;

int 
main(int argc, char **argv) {
    char *str = NULL;

    str = PTR_UNWRAP (calloc(10, sizeof(*str)))
    UNWRAP_PTR(strcpy(str, "hello"));
    printf("%s", str);

    return 0;
}
