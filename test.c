#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zic.h"

result
defer_close_file(int argc, char **argv) DEF
    char file[] = "file1";
    FILE *fp;
    char ch;

    fp = PTR_UNWRAP(fopen(file, "r"))
    DEFER_FCLOSE(fp)

    ch = fgetc(fp);
    fputc(ch, stdout);
    printf("\nthats all!\n");
    FAIL()
END


result
defer_free_t(int argc, char **argv) DEF 
    char *str = NULL;

    str = PTR_UNWRAP (calloc(10, sizeof(*str)))
    DEFER_FREE(str)

    if (argc != 2) {
        ERROR(ERR_USER)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR(ERR_USER)
    }

    UNWRAP_PTR(strcpy(str, argv[1]));
    printf("%s\n", str);
    OK()
END

int
main(int argc, char **argv) DEF
    return defer_close_file(argc, argv);
END
