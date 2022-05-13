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

    fp = PTR_UNWRAP (fopen(file, "r"))
    DEFER1_FINAL(fclose(fp))
    printf("%p\n", fp);

    ch = fgetc(fp);
    UNWRAP_NEG (fputc(ch, stdout), final)
END_CLEAN


result
defer_free_t(int argc, char **argv) DEF
    char *str = NULL;
    FILE *fp = NULL;

    fp = PTR_UNWRAP (fopen("file1", "r"))
    DEFER1(close_file, fclose(fp))

    str = PTR_UNWRAP (calloc(10, sizeof(*str)), close_file)
    DEFER2_FINAL(free(str))

    if (argc != 2) {
        ERROR(ERR_USER, final)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR(ERR_USER, final)
    }
    
    strcpy(str, argv[1]);
    UNWRAP (puts(str), final);
    OK()
END

int
main(int argc, char **argv) DEF
    MATCH defer_free_t(argc, argv) WITH (
        OK: return OK,
        ERR_USER: CATCH("Nu i che tu"),
        default: FAIL() 
    )
END_CLEAN
