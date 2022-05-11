#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "zic.h"

result
defer_close_file(int argc, char **argv) DEF
    char file[] = "file1";
    FILE *fp;
    char ch;

    fp = fopen(file, "r");
    printf("%p\n", fp);

    ch = fgetc(fp);
    fputc(ch, stdout);
    FAIL()
END


result
defer_free_t(int argc, char **argv) DEF 
    char *str = NULL;

    str = PTR_UNWRAP (calloc(10, sizeof(*str)))

    if (argc != 2) {
        ERR_CLEANUP(free_str, ERR_USER)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERR_CLEANUP(free_str, ERR_USER)
    }

    UNWRAP_PTR(strcpy(str, argv[1]));
    printf("%s\n", str);

    CLEANUP(free_str, free(str))
    OK()
END()

int
main(int argc, char **argv) DEF
    return defer_close_file(argc, argv);
END
